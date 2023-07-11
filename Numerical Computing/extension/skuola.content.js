/******/ (() => { // webpackBootstrap
/******/ 	"use strict";
/******/ 	var __webpack_modules__ = ({

/***/ "./src/foreground/skuola/import/autoplayRemover.ts":
/*!*********************************************************!*\
  !*** ./src/foreground/skuola/import/autoplayRemover.ts ***!
  \*********************************************************/
/***/ ((__unused_webpack_module, exports) => {

var __webpack_unused_export__;

// Copyright 2021-2022 rospino74
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
__webpack_unused_export__ = ({ value: true });
function observerCallback(mutations, observer) {
    mutations.forEach(function (mutation) {
        var videoElement = mutation.addedNodes[0];
        if (videoElement && videoElement.tagName === 'VIDEO') {
            setTimeout(function () {
                var _a, _b, _c, _d, _e;
                var playBtn = (_a = videoElement.parentElement) === null || _a === void 0 ? void 0 : _a.querySelector('.vjs-play-control.vjs-playing');
                if (playBtn) {
                    playBtn.click();
                }
                // Close the mini player
                var closeMiniPlayerBtn = (_e = (_d = (_c = (_b = videoElement.parentElement) === null || _b === void 0 ? void 0 : _b.parentElement) === null || _c === void 0 ? void 0 : _c.parentElement) === null || _d === void 0 ? void 0 : _d.parentElement) === null || _e === void 0 ? void 0 : _e.querySelector('.sknet-sticky-close-button');
                if (closeMiniPlayerBtn) {
                    closeMiniPlayerBtn.click();
                }
                // Mute the video
                videoElement.muted = true;
                // Remove autoplay attribute
                videoElement.removeAttribute('autoplay');
                videoElement.autoplay = false;
                // Pause the video
                videoElement.pause();
                if (true) {
                    if (/^it\b/.test(navigator.language)) {
                        console.log('Ho intercettato un video: %o', videoElement);
                    }
                    else {
                        console.log('Found a video: %o', videoElement);
                    }
                }
                observer.disconnect();
            }, 500);
        }
    });
}
function manipulateVideoAds() {
    var videoContainers = document.querySelectorAll('#video_ads');
    if ( true && videoContainers.length > 0) {
        if (/^it\b/.test(navigator.language)) {
            console.log('Trovati %d video: %o', videoContainers.length, videoContainers);
        }
        else {
            console.log('Found %d video elements: %o', videoContainers.length, videoContainers);
        }
    }
    // Iterate over all video ads to add a ready event listener
    videoContainers.forEach(function (videoAd) {
        var observer = new MutationObserver(observerCallback);
        // Add the video element to the observer
        observer.observe(videoAd, { childList: true, subtree: true });
    });
}
exports["default"] = manipulateVideoAds;


/***/ }),

/***/ "./src/foreground/skuola/import/listenersRemover.ts":
/*!**********************************************************!*\
  !*** ./src/foreground/skuola/import/listenersRemover.ts ***!
  \**********************************************************/
/***/ ((__unused_webpack_module, exports) => {

var __webpack_unused_export__;

// Copyright 2021-2022 rospino74
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
__webpack_unused_export__ = ({ value: true });
// https://stackoverflow.com/questions/19469881 & https://stackoverflow.com/a/46986927
function removeListenersOfType(target, type) {
    if (Array.isArray(type)) {
        type.forEach(function (t) { return removeListenersOfType(target, t); });
    }
    else {
        // This will NOT remove the listeners, but will force the browser to ignore them
        target.addEventListener(type, function (event) {
            event.stopImmediatePropagation();
            return true;
        }, true);
    }
}
exports["default"] = removeListenersOfType;


/***/ })

/******/ 	});
/************************************************************************/
/******/ 	// The module cache
/******/ 	var __webpack_module_cache__ = {};
/******/ 	
/******/ 	// The require function
/******/ 	function __webpack_require__(moduleId) {
/******/ 		// Check if module is in cache
/******/ 		var cachedModule = __webpack_module_cache__[moduleId];
/******/ 		if (cachedModule !== undefined) {
/******/ 			return cachedModule.exports;
/******/ 		}
/******/ 		// Create a new module (and put it into the cache)
/******/ 		var module = __webpack_module_cache__[moduleId] = {
/******/ 			// no module.id needed
/******/ 			// no module.loaded needed
/******/ 			exports: {}
/******/ 		};
/******/ 	
/******/ 		// Execute the module function
/******/ 		__webpack_modules__[moduleId](module, module.exports, __webpack_require__);
/******/ 	
/******/ 		// Return the exports of the module
/******/ 		return module.exports;
/******/ 	}
/******/ 	
/************************************************************************/
var __webpack_exports__ = {};
// This entry need to be wrapped in an IIFE because it need to be isolated against other modules in the chunk.
(() => {
/*!****************************************!*\
  !*** ./src/foreground/skuola/index.js ***!
  \****************************************/
/* harmony import */ var _import_listenersRemover_ts__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! ./import/listenersRemover.ts */ "./src/foreground/skuola/import/listenersRemover.ts");
/* harmony import */ var _import_autoplayRemover_ts__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! ./import/autoplayRemover.ts */ "./src/foreground/skuola/import/autoplayRemover.ts");
// Copyright 2021-2022 rospino74
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//



const consoleBigStyles = [
    'color: #fee300',
    'font-size: xx-large',
].join(';');

const noRightClickElement = document.querySelectorAll('[data-rightclick]');

console.log('%cSkuola Evader %cv%s', 'color: #fee300', 'color: gray; font-style: italic;', "1.4.2");

// Rimuovo il box
const copyWallBox = document.querySelector('#rightclick');
if (copyWallBox) {
    copyWallBox.parentElement.removeChild(copyWallBox);
}

// Permetto di usare il tasto destro del mouse
noRightClickElement.forEach((element) => {
    // Abilito il menu a tendina e cut, copy & paste
    (0,_import_listenersRemover_ts__WEBPACK_IMPORTED_MODULE_0__["default"])(element, ['cut', 'copy', 'paste', 'contextmenu']);
});

// Also remove event listeners from the html element
(0,_import_listenersRemover_ts__WEBPACK_IMPORTED_MODULE_0__["default"])(document.documentElement, ['cut', 'copy', 'paste', 'contextmenu']);

if (true) {
    if (/^it\b/.test(navigator.language)) {
        console.log('%cOra puoi copiare tutti i testi che vuoi 😉', consoleBigStyles);
    } else {
        console.log('%cNow you can copy all the articles you want 😉', consoleBigStyles);
    }
}

// Prevents video ads from auto playing
(0,_import_autoplayRemover_ts__WEBPACK_IMPORTED_MODULE_1__["default"])();

})();

/******/ })()
;