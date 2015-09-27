
(function(){

	// Format projectThumbs
	var thumbs = document.getElementsByTagName('projectThumb');
	for(var i = 0; i < thumbs.length; i++){
		var thumb = thumbs[i];

		// Set background image
		var image = thumb.getAttribute('image');
		if(image)
			thumb.style.backgroundImage = 'url(' + image + ')';

		// Put the text in a 'hoverOverlay' div
		// We're making something like:
		//   <projectThumb>
		//     <div class='hoverOverlay'>
		//       <div class='paddedText'>Description</div
		//     </div>
		//   </projectThumb
		var text = thumb.innerText;
		thumb.innerHTML = '';

		var overlay = document.createElement('div');
		overlay.className = 'hoverOverlay';

		var description = document.createElement('div');
		description.className = 'paddedText';
		description.innerText = text;

		overlay.appendChild(description);
		thumb.appendChild(overlay);
	}

}());
