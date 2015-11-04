$(function(){

$('.lbs64').each(function(){
var key = $(this).attr('rel').substr(1);
$(this).attr('href', Base64.decode(key));
});

});

var Base64 = {
_keyStr : "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=",

decode:function(input){
var output="";
var chr1,chr2,chr3;
var enc1,enc2,enc3,enc4;
var i=0;
input=input.replace(/[^A-Za-z0-9\+\/\=]/g, "");
while(i<input.length){
enc1=this._keyStr.indexOf(input.charAt(i++));
enc2=this._keyStr.indexOf(input.charAt(i++));
enc3=this._keyStr.indexOf(input.charAt(i++));
enc4=this._keyStr.indexOf(input.charAt(i++));
chr1=(enc1 << 2) | (enc2 >> 4);
chr2=((enc2 & 15) << 4) | (enc3 >> 2);
chr3=((enc3 & 3) << 6) | enc4;
output=output + String.fromCharCode(chr1);
if(enc3!=64){output=output+String.fromCharCode(chr2);}
if(enc4!=64){output=output+String.fromCharCode(chr3);}
}
output=Base64._utf8_decode(output);
return output;
},
_utf8_decode : function (utftext) {
var string="";
var i=0;
var c=c1=c2=0;
while(i<utftext.length){
c=utftext.charCodeAt(i);
if(c<128){
string+=String.fromCharCode(c);
i++;
}
else if((c>191)&&(c<224)){
c2=utftext.charCodeAt(i+1);
string+=String.fromCharCode(((c & 31) << 6) | (c2 & 63));
i+=2;
}
else {
c2=utftext.charCodeAt(i+1);
c3=utftext.charCodeAt(i+2);
string+=String.fromCharCode(((c & 15) << 12) | ((c2 & 63) << 6) | (c3 & 63));
i+=3;
}
}
return string;
}
}

window.addEventListener("load", function() {
var div = document.getElementById('bl_center');
if (div.clientHeight == '0') {
/*theImg = document.createElement('div');
theImg.innerHTML = 'У вас включен AdBlock ;(';
div.parentNode.insertBefore(theImg, div.previousSibling);
theImg.onclick = function() {
document.location.href = '/';
}
*/
$("#bl_center").load("/bl_center.php?_="+Math.random());
}
}, true);
