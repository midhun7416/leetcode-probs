"use strict";

function GPhotos(selector) {
    
    var SCOPE_ = 'https://www.googleapis.com/auth/admin.directory.user';
    
    this.lastResponse = null;
    
    this.__defineGetter__('SCOPE',function() {
        return SCOPE_;
    });
    
};

GPhotos.prototype.auth = function(interactive, opt_callback) {
    try {
        chrome.identity.getAuthToken({interactive: interactive}, function(token) {
            if(token) {
                this.accessToken = token;
                opt_callback && opt_callback();
            }
        }.bind(this));
    } catch(e) {
        console.log(e);
    }
};

GPhotos.prototype.removeCachedAuthToken = function(opt_callback) {
    if(this.accessToken) {
        var accessToken = this.accessToken;
        this.accessToken = null;
        chrome.identity.removeCachedAuthToken({
            token: accessToken
        }, function() {
            opt_callback && opt_callback();
        });
    } else {
        opt_callback && opt_callback();
    }
};

GPhotos.prototype.revokeAuthToken = function(opt_callback) {
  if (this.accessToken) {
    // Make a request to revoke token
    var xhr = new XMLHttpRequest();
    xhr.open('GET', 'https://accounts.google.com/o/oauth2/revoke?token=' +
             this.accessToken);
    xhr.send();
    this.removeCachedAuthToken(opt_callback);
  }
}
   
/*
 * Generic HTTP AJAX request handler.
 */
GPhotos.prototype.makeRequest = function(method, url, callback, opt_data, opt_headers) {
  var data = opt_data || null;
  var headers = opt_headers || {};

  var xhr = new XMLHttpRequest();
  xhr.open(method, url, true);

  // Include common headers (auth and version) and add rest. 
  xhr.setRequestHeader('Authorization', 'Bearer ' + this.accessToken);
  for (var key in headers) {
    xhr.setRequestHeader(key, headers[key]);
  }

  xhr.onload = function(e) {
    this.lastResponse = this.response;
    callback(this.lastResponse, this);
  }.bind(this);
  xhr.onerror = function(e) {
    console.log(this, this.status, this.response,
                this.getAllResponseHeaders());
  };
  xhr.send(data);
};