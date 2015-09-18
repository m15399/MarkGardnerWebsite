
(function(){

	// Fill the 'nav' div, if found
	var nav = document.getElementsByTagName('nav')[0];
	if(nav){
		nav.innerHTML = '<ul>\
			<a href="index.html"><li class="active">Home</li></a>\
			<a href="index.html"><li>Projects</li></a>\
			<a href="index.html"><li>About Me</li></a>\
			<a href="index.html"><li>Contact</li></a>\
			</ul>';
	}

}());
