"use strict";

function entry() {
    var
        login = "",
        password = "";


    var authWindow = window.open("about:blank", "hello", "width=200,height=200");

    //login = prompt("Введите логин(если нет логина, используйте номер страхового полиса)");

   // alert(login);
    password = prompt("Введите пароль");

    alert(password);

}