//Modified media player JS - Most original code comes from credit below
//with additions and revisions by Michael King, http://www.osc.org (c) 2014

// Ian Devlin (c) 2012
// http://iandevlin.com
// http://twitter.com/iandevlin
// This was written as part of an article for the February 2013 edition of .net magazine (http://netmagazine.com/)


// Wait for the DOM to be loaded before initialising the media player
document.addEventListener("DOMContentLoaded", function() { initialiseMediaPlayer(); }, false);

// Variables to store handles to various required elements
var mediaPlayer;
var playPauseBtn;
var muteBtn;
var nextBtn;
var video_count = 1;
var currentFileNum = 1;


function initialiseMediaPlayer() {
	// Get a handle to the player
	mediaPlayer = document.getElementById('media-video');
	
	// Hide the browser's default controls
	mediaPlayer.controls = false;
	
	// Add a listener for the play and pause events so the buttons state can be updated
	mediaPlayer.addEventListener('play', function() {
		// Change the button to be a pause button
//		changeButtonType(playPauseBtn, 'pause');
	}, false);
	mediaPlayer.addEventListener('pause', function() {
		// Change the button to be a play button
//		changeButtonType(playPauseBtn, 'play');
	}, false);
	
	mediaPlayer.addEventListener('ended', function() { this.pause(); }, false);	
}

function togglePlayPause() {
	// If the mediaPlayer is currently paused or has ended
	if (mediaPlayer.paused || mediaPlayer.ended) {
		// Change the button to be a pause button
//		changeButtonType(playPauseBtn, 'pause');
		// Play the media
		mediaPlayer.play();
	}
	// Otherwise it must currently be playing
	else {
		// Change the button to be a play button
//		changeButtonType(playPauseBtn, 'play');
		// Pause the media
		mediaPlayer.pause();
	}
}

// Stop the current media from playing, and return it to the start position
function stopPlayer() {
	mediaPlayer.pause();
	mediaPlayer.currentTime = 0;
}


// Replays the media currently loaded in the player
function replayMedia() {
	resetPlayer();
	mediaPlayer.play();
}

function nextVideo() {
	video_count = currentFileNum; 
	video_count ++;
	if (video_count >= totalvids) video_count = totalvids;
	var readyVideo = "video/fullvids/" + design + "/step" + video_count + ".mp4";
	loadVideo(readyVideo);
}

function prevVideo() {
	video_count = currentFileNum; 
	video_count --;
	if (video_count <= 1) video_count = 1
	var readyVideo = "video/fullvids/" + design + "/step" + video_count + ".mp4";
	loadVideo(readyVideo);
}

	

// Updates a button's title, innerHTML and CSS class to a certain value
function changeButtonType(btn, value) {
	btn.title = value;
	btn.innerHTML = value;
	btn.className = value;
}


// Loads a video item into the media player
function loadVideo() {
	for (var i = 0; i < arguments.length; i++) {
		var file = arguments[i].split('.');
		var filename = file[0].split("step");
		currentFileNum = filename[1]
		setVisibility();
		var ext = file[file.length - 1];
		// Check if this media can be played
		if (canPlayVideo(ext)) {
			// Reset the player, change the source file and load it
			resetPlayer();
			mediaPlayer.src = arguments[i];
			mediaPlayer.load();
			break;
		}
	}
}

function setVisibility(){ // Sets visibility of prev/next buttons
	if (currentFileNum >= 1)
			document.getElementById("previousButton").style.visibility = 'hidden' ;
	if (currentFileNum > 1)
			document.getElementById("previousButton").style.visibility = 'visible' ;

	if (currentFileNum >= totalvids)
			document.getElementById("nextButton").style.visibility = 'hidden' ;
	if (currentFileNum < totalvids)
			document.getElementById("nextButton").style.visibility = 'visible' ;
		}

// Checks if the browser can play this particular type of file or not
function canPlayVideo(ext) {
	var ableToPlay = mediaPlayer.canPlayType('video/' + ext);
	if (ableToPlay == '') return false;
	else return true;
}

// Resets the media player
function resetPlayer() {
	// Reset the progress bar to 0
    // progressBar.value = 0;
	// Move the media back to the start
	mediaPlayer.currentTime = 0;
	// Ensure that the play pause button is set as 'play'
//	changeButtonType(playPauseBtn, 'play');
}