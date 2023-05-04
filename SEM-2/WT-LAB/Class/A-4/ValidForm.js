function formValidator() {
 var firstName = document.getElementById('fname');
 var lastName = document.getElementById('lname');
 var email = document.getElementById('mail');
 var pass = document.getElementById('pswrd');
 var addr = document.getElementById('add');
 var mobile = document.getElementById('mobile');
 if(NameValidator(firstName))
 if(NameValidator(lastName))
 if(passwordValidator(pass))
 if(mobValidator(mobile) && isNumeric(mobile))
 return true;
 return false;
}
function isNumeric(mob) {
 var exp = /^[0-9]+$/;
 if(!mob.value.match(exp)) {
 alert('Mobile number should not be characters');
 mob.focus();
 return false;
 }
 return true;
}
function mobValidator(mob) {
 if(mob.value.length!=10) {
 alert('Mobile Number must be of 10 digits');
 mob.focus();
 return false;
 }
 return true;
}
function NameValidator(fname) {
 var alphaExp = /^[a-zA-Z]+$/;
 if(fname.value.length<6) {
 alert('Name should not be less than 6 characters');
 fname.focus();
 return false;
 } else if(!fname.value.match(alphaExp)) {
 alert('Enter only alphabets for Name');
 fname.focus();
 return false;
 }
 return true;
}
function passwordValidator(pass) {
 if(pass.value.length<6) {
 alert('Password should not be less than 6 characters');
 pass.focus();
 return false;
 }
 return true;
}
