function onError(e) {
  console.log(e);
}


var gPhotoApp = angular.module('gPhotoApp', []);

gPhotoApp.factory('gphotos', function() {
  var gphotos = new GPhotos();

  /*var dnd = new DnDFileController('body', function(files) {
    var $scope = angular.element(this).scope();
    Util.toArray(files).forEach(function(file, i) {
      gdocs.upload(file, function() {
        $scope.fetchDocs(true);
      }, true);
    });
  });*/

});

gPhotoApp.controller('photoController', ['$scope', '$http', 'gphotos', function($scope, $http, gphotos) {
  $scope.photos = [];
    
  $scope.clearPhotos = function() {
    $scope.photos = [];
  };
  
  $scope.getPhotos = function(retry) {
      this.clearPhotos();
      
      if (gphotos.accessToken) {
          var config = {
              params: {'alt': 'json'},
              headers: {
                  'Authorization': 'Bearer ' + gphotos.accessToken
              }
          }
          console.log(config);
          /*$http.get(config).
          success().
          error(function(data, status, headers, config) {
              if(status == 401 && retry) {
                  gphotos.removeCachedAuthToken(
                      gphotos.auth.bind(gphotos, true, 
                                        $scope.getPhotos.bind($scope, false)));
              }
          });*/
      }
  };
  
      // Toggles the authorization state.
  $scope.toggleAuth = function(interactive) {
    if (!gphotos.accessToken) {
      gphotos.auth(interactive, function() {
        $scope.getPhotos(false);
      });
    } else {
      gphotos.revokeAuthToken(function() {});
      this.clearPhotos();
    }
  };

  // Controls the label of the authorize/deauthorize button.
  $scope.authButtonLabel = function() {
    if (gphotos.accessToken)
      return 'Deauthorize';
    else
      return 'Authorize';
  };

  $scope.toggleAuth(false);

}]);

//photoController.$inject = [];

// Init setup and attach event listeners.
document.addEventListener('DOMContentLoaded', function(e) {
  var closeButton = document.querySelector('#close-button');
  closeButton.addEventListener('click', function(e) {
    window.close();
    console.log('Window close called');
  });

  // FILESYSTEM SUPPORT --------------------------------------------------------
  /*window.webkitRequestFileSystem(TEMPORARY, 1024 * 1024, function() {
    
  }, onError);*/
  // ---------------------------------------------------------------------------
});