
// Function to load a script onto the page
// Usage: loadScript(filename);
var loadScript;


(function(){

	var head = document.getElementsByTagName('head')[0];

	loadScript = function(filename){
		var node = document.createElement('script');
		node.src = filename;

		head.appendChild(node);

	}

	// Load default scripts
	loadScript('classSystem.js');
	loadScript('setup.js');

}());


