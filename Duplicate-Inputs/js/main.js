/**
 ================================== IMPORTANT! =================================
 * Written by Naseebullah Ahmadi <javastastic@gmail.com>, July 2016
 * @date 2016/07/31 12:28:00
 * @website http://fullstackdeveloper.co
 * ============================
 * @author Naseebullah Ahmadi
 * @since 31/07/2016
 * @version v1.2.1
 ================================== IMPORTANT! =================================
 **/
var DATA = (function($) {
  /**
   * I'm Telling browsers that we’re not doing anything silly,
   * and it should use the faster parsing engine
   **/
  'use strict';
  var inputArray = [];
  /**
	> triggered when the user clicks the submit button.
	> calling another function to validate the data
	**/
  var submitForm = function() {
		$("form[name=submitForm]").submit(function(e) {
			// prevent page refresh
			e.preventDefault();
			validateNumbers(getNumbers());
		});
	};

	/**
		> Looping through our inputs value and pushing it into array
		> an if statement that checks {
			> there is no duplicates
			> The number is between the range of 1 and 75
			> and the data is a number
		}
	@return list of values
	**/
  var validateNumbers = function(numbers) {
		for (var i = 0; i < numbers.length; i++) {
      var indexValue = numbers[i].value;
      var indexID = numbers[i].id;
			inputArray.push({
				ID: indexID,
        Value: indexValue
			});
		}

    var number     = Boolean(isNumber(numbers));
    var duplciates = Boolean(hasDuplicates(inputArray));
    var range      = Boolean(checkNumberRange(numbers).length < 1);

		if (number && duplciates && range) {
			console.log("Success! Processing Data...");
			$.ajax({
				type: "POST",
        url: "php/main.php",
        data: {
					getVal: JSON.stringify(inputArray)
				},
				success: function(response) {
					console.log(response);
				}
			});
		} else {
			console.log("Wrong Data Injected!");
		}
	};

	/**
		> @return list of inputs
	**/
  var getNumbers = function() {
    var ul = document.getElementById("inputs");
    var items = ul.getElementsByTagName("input");
    return items;
  };

	/**
		> We have an array of values that was pushed from validateNumbers function
		> We loop through the array {
			> check whether a number in given index repeats itself in another index
		}
	@return array
	**/
  var hasDuplicates = function(data) {
  	var counter = {};
    for (var i = 0; i < data.length; i++) {
			counter[data[i].Value] = (counter[data[i].Value] || 0) + 1;
		}

		var output = true;
		for (var key in counter) {
		   if (counter[key] > 1) {
		     output = false;
		   }
		}
		return output;
	};

	/**
		> Check whether the value is within range
	**/
  var checkNumberRange = function(data) {
    var newArray = [];
		Number.prototype.between = function(min, max) {
			return this > min && this < max;
    };

		for (var i = 0; i < data.length; i++) {
			if (!(Number(data[i].value).between(0, 76))) {
				newArray.push(Number(data[i].value));
			}
		}
		console.log(newArray);
		return newArray;
	};

	/**
		> Check whether the value within the array is a number
	**/
  var isNumber = function(data) {
    Number.prototype.between = function(min, max) {
    	return this > min && this < max;
    };

		for (var i = 0; i < data.length; i++) {
			if (!isNaN(data[i].value)) {
				return true;
			} else {
				return false;
			}
		}
	};

	/**
  	* Fire events on document ready, and bind other events.
  	* calling private methods
  	* @return nothing
  **/
  var initialize = function() {
    submitForm();
  };

	// Only expose the ready function to the world!
  return {
    initialize: initialize
  };

})(jQuery);
jQuery(DATA.initialize);
