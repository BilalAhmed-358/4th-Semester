/******/ (() => { // webpackBootstrap
/******/ 	"use strict";
/******/ 	var __webpack_modules__ = ({

/***/ "./src/foreground/studenti/import/getFileDownloadUrl.ts":
/*!**************************************************************!*\
  !*** ./src/foreground/studenti/import/getFileDownloadUrl.ts ***!
  \**************************************************************/
/***/ (function(__unused_webpack_module, exports) {


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
var __awaiter = (this && this.__awaiter) || function (thisArg, _arguments, P, generator) {
    function adopt(value) { return value instanceof P ? value : new P(function (resolve) { resolve(value); }); }
    return new (P || (P = Promise))(function (resolve, reject) {
        function fulfilled(value) { try { step(generator.next(value)); } catch (e) { reject(e); } }
        function rejected(value) { try { step(generator["throw"](value)); } catch (e) { reject(e); } }
        function step(result) { result.done ? resolve(result.value) : adopt(result.value).then(fulfilled, rejected); }
        step((generator = generator.apply(thisArg, _arguments || [])).next());
    });
};
var __generator = (this && this.__generator) || function (thisArg, body) {
    var _ = { label: 0, sent: function() { if (t[0] & 1) throw t[1]; return t[1]; }, trys: [], ops: [] }, f, y, t, g;
    return g = { next: verb(0), "throw": verb(1), "return": verb(2) }, typeof Symbol === "function" && (g[Symbol.iterator] = function() { return this; }), g;
    function verb(n) { return function (v) { return step([n, v]); }; }
    function step(op) {
        if (f) throw new TypeError("Generator is already executing.");
        while (_) try {
            if (f = 1, y && (t = op[0] & 2 ? y["return"] : op[0] ? y["throw"] || ((t = y["return"]) && t.call(y), 0) : y.next) && !(t = t.call(y, op[1])).done) return t;
            if (y = 0, t) op = [op[0] & 2, t.value];
            switch (op[0]) {
                case 0: case 1: t = op; break;
                case 4: _.label++; return { value: op[1], done: false };
                case 5: _.label++; y = op[1]; op = [0]; continue;
                case 7: op = _.ops.pop(); _.trys.pop(); continue;
                default:
                    if (!(t = _.trys, t = t.length > 0 && t[t.length - 1]) && (op[0] === 6 || op[0] === 2)) { _ = 0; continue; }
                    if (op[0] === 3 && (!t || (op[1] > t[0] && op[1] < t[3]))) { _.label = op[1]; break; }
                    if (op[0] === 6 && _.label < t[1]) { _.label = t[1]; t = op; break; }
                    if (t && _.label < t[2]) { _.label = t[2]; _.ops.push(op); break; }
                    if (t[2]) _.ops.pop();
                    _.trys.pop(); continue;
            }
            op = body.call(thisArg, _);
        } catch (e) { op = [6, e]; y = 0; } finally { f = t = 0; }
        if (op[0] & 5) throw op[1]; return { value: op[0] ? op[1] : void 0, done: true };
    }
};
Object.defineProperty(exports, "__esModule", ({ value: true }));
function getFileDownloadUrl(documentId) {
    return __awaiter(this, void 0, void 0, function () {
        var apiUrl, body, response, json;
        return __generator(this, function (_a) {
            switch (_a.label) {
                case 0:
                    apiUrl = "https://doc.studenti.it/ajax/download.php";
                    body = "k=".concat(documentId);
                    return [4 /*yield*/, fetch(apiUrl, {
                            method: 'POST',
                            headers: {
                                'Content-Type': 'application/x-www-form-urlencoded',
                                'Content-Length': body.length.toString(),
                            },
                            body: body
                        })];
                case 1:
                    response = _a.sent();
                    // Watch out for http errors
                    if (!response.ok) {
                        throw new Error("".concat(response.status, " ").concat(response.statusText));
                    }
                    return [4 /*yield*/, response.json()];
                case 2:
                    json = _a.sent();
                    // Response object
                    if (true) {
                        console.log(json);
                    }
                    if (json.esito != 'OK') {
                        throw new Error("".concat(response.status, " ").concat(response.statusText, ": ").concat(json.messaggio));
                    }
                    if (true) {
                        if (/^it\b/.test(navigator.language)) {
                            console.log('%cIndirizzo del download: %c%s', 'color: #7ab700;', 'color: gray;', json.link);
                        }
                        else {
                            console.log('%cDownload url: %c%s', 'color: #7ab700;', 'color: gray;', json.link);
                        }
                    }
                    return [2 /*return*/, json.link];
            }
        });
    });
}
exports["default"] = getFileDownloadUrl;


/***/ }),

/***/ "./src/foreground/studenti/index.ts":
/*!******************************************!*\
  !*** ./src/foreground/studenti/index.ts ***!
  \******************************************/
/***/ (function(__unused_webpack_module, exports, __webpack_require__) {


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
var __importDefault = (this && this.__importDefault) || function (mod) {
    return (mod && mod.__esModule) ? mod : { "default": mod };
};
Object.defineProperty(exports, "__esModule", ({ value: true }));
var getFileDownloadUrl_1 = __importDefault(__webpack_require__(/*! ./import/getFileDownloadUrl */ "./src/foreground/studenti/import/getFileDownloadUrl.ts"));
console.log('%cStudenti.it %cv%s', 'color: #7ab700;', 'color: gray; font-style: italic;', "1.4.2");
var appuntiRegex = /appunti\/[a-zA-Z0-9\-/]+\.html/gm;
var urlPageIdRegex = /\?h=([a-zA-Z0-9\-]+)/gm;
var pageId;
// Check if the page is an appunti page
if (appuntiRegex.test(window.location.href)) {
    pageId = getNextPageId();
    removeAdvertisingLink(pageId);
    // Remove right arrow button
    var rightArrowButtons = document.querySelectorAll(".pager ul li:last-child");
    rightArrowButtons.forEach(function (btn) { var _a; return (_a = btn.parentElement) === null || _a === void 0 ? void 0 : _a.removeChild(btn); });
}
else {
    pageId = urlPageIdRegex.exec(window.location.href)[1];
    var relatedPageButton = document.querySelectorAll(".pager ul li a[href*=correlati]");
    relatedPageButton.forEach(function (btn) {
        var _a;
        if (true) {
            if (/^it\b/.test(navigator.language)) {
                console.log("%cRimuovo l'ultimo bottone: %o", 'color: #7ab700', btn);
            }
            else {
                console.log("%cRemoving last button: %o", 'color: #7ab700', btn);
            }
        }
        var li = btn.parentElement;
        (_a = li === null || li === void 0 ? void 0 : li.parentElement) === null || _a === void 0 ? void 0 : _a.removeChild(li);
    });
    // Modifing the total count of pages
    var totalPageCounters = document.querySelectorAll(".pager span b:nth-child(2)");
    if (totalPageCounters) {
        totalPageCounters.forEach(function (counter) {
            var currentPageCount = parseInt(counter.innerText) - 1;
            counter.innerText = currentPageCount.toString();
        });
    }
    // Gets the download button
    var downloadButton = document.querySelector("a.download-doc");
    if (downloadButton) {
        downloadButton.href = '#';
        downloadButton === null || downloadButton === void 0 ? void 0 : downloadButton.addEventListener('click', function (evt) {
            evt.preventDefault();
            if (true) {
                if (/^it\b/.test(navigator.language)) {
                    console.log('%cChiedo url download...', 'color: #7ab700;');
                }
                else {
                    console.log('%cRequesting download url...', 'color: #7ab700;');
                }
            }
            (0, getFileDownloadUrl_1.default)(pageId).then(function (url) {
                // Open the url
                window.location.href = url;
            });
        });
    }
}
function getNextPageId() {
    // Grabbing the url from the button
    var nextPageUrl = document.querySelector(".pager ul li:nth-child(2) a").href;
    var pageIdRegex = /download_2\/([a-zA-Z0-9\-]+)_1\.html/gm;
    if (true) {
        if (/^it\b/.test(navigator.language)) {
            console.log('%cIndirizzo prossima pagina: %s', 'color: #7ab700;', nextPageUrl);
        }
        else {
            console.log('%cNext page url: %s', 'color: #7ab700;', nextPageUrl);
        }
    }
    return pageIdRegex.exec(nextPageUrl)[1];
}
function removeAdvertisingLink(id) {
    var baseUrl = "https://doc.studenti.it/vedi_tutto/index.php?h=".concat(id);
    var nextPageButton = document.querySelectorAll(".pager ul li a");
    nextPageButton.forEach(function (btn) {
        var pageNumber = parseInt(btn.innerText);
        if (pageNumber === 1) {
            if (true) {
                if (/^it\b/.test(navigator.language)) {
                    console.log('%cSalto il primo bottone: %o', 'color: #7ab700', btn);
                }
                else {
                    console.log('%cSkipping first button: %o', 'color: #7ab700', btn);
                }
            }
            return;
        }
        if (true) {
            if (/^it\b/.test(navigator.language)) {
                console.log("%cCambio URL %c%s %c-> %c%s", 'color: #7ab700;', 'color: red;', btn.href, 'color: gray;', 'color: green;', "".concat(baseUrl, "&pag=").concat(pageNumber - 1));
            }
            else {
                console.log("%cChanging URL %c%s %c-> %c%s", 'color: #7ab700;', 'color: red;', btn.href, 'color: gray;', 'color: green;', "".concat(baseUrl, "&pag=").concat(pageNumber - 1));
            }
        }
        btn.href = "".concat(baseUrl, "&pag=").concat(pageNumber - 1);
    });
}


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
/******/ 		__webpack_modules__[moduleId].call(module.exports, module, module.exports, __webpack_require__);
/******/ 	
/******/ 		// Return the exports of the module
/******/ 		return module.exports;
/******/ 	}
/******/ 	
/************************************************************************/
/******/ 	
/******/ 	// startup
/******/ 	// Load entry module and return exports
/******/ 	// This entry module is referenced by other modules so it can't be inlined
/******/ 	var __webpack_exports__ = __webpack_require__("./src/foreground/studenti/index.ts");
/******/ 	
/******/ })()
;