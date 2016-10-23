/**
================================== IMPORTANT! ==================================
* @author Naseebullah Ahmadi
* @since 20/10/2016
* @version v1
================================== IMPORTANT! ==================================
**/
var POWER = {};
POWER = (function () {
  /**
   * I'm Telling browsers that we’re not doing anything silly,
   * and it should use the faster parsing engine
  **/
  'use strict';

  var property = function(number) {
    var getNumber         = number,
    numberArray           = [],
    convertNumberToString = getNumber.toString();

    for (var i = 0; i < convertNumberToString.length; i++) {
      numberArray.push(
        +convertNumberToString.charAt(i)
      );
    }
    //console.log( Math.pow(numberArray[1],2) );

    var add = 0;
    for (var j = 0; j < numberArray.length; j++) {
      add = Math.pow(numberArray[j],j+1);
    }

    console.log(add);
  };



  var initialize = function() {
    // calling functions here
    property(89);
  };

  /*
    > public - only return is available to the public
  */
  return {
    initialize : initialize()
  };

})();
