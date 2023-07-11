/******/ (() => { // webpackBootstrap
/******/ 	"use strict";
/******/ 	var __webpack_modules__ = ({

/***/ "./src/background/background.ts":
/*!**************************************!*\
  !*** ./src/background/background.ts ***!
  \**************************************/
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
var cookieReplacer_1 = __importDefault(__webpack_require__(/*! ./cookieReplacer */ "./src/background/cookieReplacer.ts"));
var latinAjaxInterceptor_1 = __importDefault(__webpack_require__(/*! ./latinAjaxInterceptor */ "./src/background/latinAjaxInterceptor.ts"));
// Provo ad intercettare le richieste
(0, latinAjaxInterceptor_1.default)();
// Listening for messages from the content script
chrome.runtime.onMessage.addListener(function (message) {
    if (true) {
        console.log('Message received from content script:', message);
    }
    var action = message.action, tab = message.tab, value = message.value;
    if (action === 'copyCookies') {
        if (true) {
            console.warn('Account cookies received: ', value);
        }
        (0, cookieReplacer_1.default)(value);
    }
    else if (action === 'refresh') {
        if (true) {
            console.warn('Refresh received');
        }
        chrome.tabs.reload(tab.id).catch(function () {
            chrome.tabs.update(tab.id, { url: tab.url });
        });
    }
});


/***/ }),

/***/ "./src/background/cookieReplacer.ts":
/*!******************************************!*\
  !*** ./src/background/cookieReplacer.ts ***!
  \******************************************/
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
function replaceQuizletCookies(extensionCookies) {
    return __awaiter(this, void 0, void 0, function () {
        var _this = this;
        return __generator(this, function (_a) {
            // Itero tutti i cookies dell'estensione
            extensionCookies.split('; ').forEach(function (cookie) { return __awaiter(_this, void 0, void 0, function () {
                var _a, cookieName, cookieValue;
                return __generator(this, function (_b) {
                    switch (_b.label) {
                        case 0:
                            _a = cookie.split('='), cookieName = _a[0], cookieValue = _a[1];
                            // Salvo il cookie nel browser
                            return [4 /*yield*/, chrome.cookies.set({
                                    url: 'quizlet.com',
                                    name: cookieName,
                                    value: cookieValue,
                                })];
                        case 1:
                            // Salvo il cookie nel browser
                            _b.sent();
                            return [2 /*return*/];
                    }
                });
            }); });
            return [2 /*return*/];
        });
    });
}
exports["default"] = replaceQuizletCookies;


/***/ }),

/***/ "./src/background/latinAjaxInterceptor.ts":
/*!************************************************!*\
  !*** ./src/background/latinAjaxInterceptor.ts ***!
  \************************************************/
/***/ (function(__unused_webpack_module, exports, __webpack_require__) {


// Copyright 2021-2022 rospino74
//
// Licensed under the Apache License, Version 2.0 (the 'License');
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an 'AS IS' BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
var __importDefault = (this && this.__importDefault) || function (mod) {
    return (mod && mod.__esModule) ? mod : { "default": mod };
};
Object.defineProperty(exports, "__esModule", ({ value: true }));
var userSelectRemover_1 = __importDefault(__webpack_require__(/*! ../foreground/latin/import/userSelectRemover */ "./src/foreground/latin/import/userSelectRemover.ts"));
function firefoxListener(details) {
    // @ts-ignore
    var filter = browser.webRequest.filterResponseData(details.requestId);
    var decoder = new TextDecoder('utf-8');
    var encoder = new TextEncoder();
    filter.ondata = function (event) {
        var str = decoder.decode(event.data, { stream: true });
        // If the string is protected, we don't modify it
        if (str.includes('Protected')) {
            if (true) {
                console.warn('Protected page detected, not modifying');
            }
            filter.write(encoder.encode(str));
            filter.disconnect();
            return;
        }
        // Elimino l'anty copy
        str = parseAndRemove(str);
        if (true) {
            console.log("Modified HTML:\n".concat(str));
        }
        // Invio la risposta
        filter.write(encoder.encode(str));
        filter.disconnect();
    };
    return {};
}
function chromeListener(details) {
    // Fetching the response body via XMLHttpRequest
    var xhr = new XMLHttpRequest();
    xhr.open('GET', details.url, false);
    xhr.send();
    if (true) {
        console.log("Response recieved from ".concat(details.url, " with HTTP status code ").concat(xhr.status, " ").concat(xhr.statusText));
    }
    if (xhr.status !== 200 || xhr.responseText.includes('Protected'))
        return {};
    // Remove the anti-copy system
    var parsed = parseAndRemove(xhr.responseText);
    if (true) {
        console.log("Modified HTML:\n".concat(parsed));
    }
    // Getting the modified data url and redirecting the user
    var dataURL = "data:text/html,".concat(encodeURIComponent(parsed));
    return {
        redirectUrl: dataURL,
    };
}
function parseAndRemove(str) {
    // Creo un elemento template
    var template = document.createElement('template');
    template.innerHTML = str;
    // Elimino l'anty copy
    var noCopyBoxes = template.content.querySelectorAll('[style*=user-select]');
    (0, userSelectRemover_1.default)(noCopyBoxes);
    // Estraggo html
    return template.innerHTML;
}
function installLatinAjaxInterceptor() {
    try {
        // @ts-ignore
        if (typeof browser !== 'undefined') {
            // @ts-ignore
            browser.webRequest.onBeforeRequest.addListener(firefoxListener, { urls: ['https://www.latin.it/ajax_traduzione_frase.php?*', 'https://www.latin.it/ajax_traduzione_versione.php?*'] }, ['blocking']);
            if (true) {
                if (/^it\b/.test(navigator.language)) {
                    console.log("%cSistema anti-anti-copiatura installato. %cL'anti-copy evader è supportato pienamente solo su Firefox, per info: https://bugs.chromium.org/p/chromium/issues/detail?id=104058", 'color: #80f5ab;', 'color: gray; font-style: italic;');
                }
                else {
                    console.log("%cThe anti-anti-copy system has been installed. %cThe anti-copy evader is fully supported on Firefox only, for info: https://bugs.chromium.org/p/chromium/issues/detail?id=104058", 'color: #80f5ab;', 'color: gray; font-style: italic;');
                }
            }
        }
        else {
            chrome.webRequest.onBeforeRequest.addListener(chromeListener, { urls: ['https://www.latin.it/ajax_traduzione_frase.php?*', 'https://www.latin.it/ajax_traduzione_versione.php?*'] }, ['blocking']);
        }
    }
    catch (e) {
        if (true) {
            if (/^it\b/.test(navigator.language)) {
                console.log("%cImpossibile intercettare le risposte. Il sistema anti anti copiatura è pienamente supportato solo Firefox. %cL'anti-copy evader non sarà disponibile.\n\n%cPer info: %chttps://bugs.chromium.org/p/chromium/issues/detail?id=104058", 'color: #f04747;', 'color: gray; font-style: italic;', 'color: #009dd9;', 'color: gray; font-style: italic;');
            }
            else {
                console.log("%cUnable to intercept solutions. The anti-anti-copy system is fully supported only Firefox. %cThe anti-copy evader will not be available.\n\n%cFor info: %chttps://bugs.chromium.org/p/chromium/issues/detail?id=104058", 'color: #f04747;', 'color: gray; font-style: italic;', 'color: #009dd9;', 'color: gray; font-style: italic;');
            }
            console.error(e);
        }
    }
}
exports["default"] = installLatinAjaxInterceptor;


/***/ }),

/***/ "./src/foreground/latin/import/userSelectRemover.ts":
/*!**********************************************************!*\
  !*** ./src/foreground/latin/import/userSelectRemover.ts ***!
  \**********************************************************/
/***/ ((__unused_webpack_module, exports) => {


// Copyright 2021-2022 rospino74
//
// Licensed under the Apache License, Version 2.0 (the 'License');
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an 'AS IS' BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
Object.defineProperty(exports, "__esModule", ({ value: true }));
function userSelectRemover(element) {
    if (element instanceof NodeList) {
        element.forEach(remove);
    }
    else {
        remove(element);
    }
}
exports["default"] = userSelectRemover;
function remove(element) {
    // Proprietà non standard
    try {
        /// @ts-ignore
        element.style.MozUserSelect = 'text';
        /// @ts-ignore
        element.style.WebkitUserSelect = 'text';
    }
    catch (_a) { }
    // Proprietà standard
    element.style.userSelect = 'text';
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
/******/ 	var __webpack_exports__ = __webpack_require__("./src/background/background.ts");
/******/ 	
/******/ })()
;