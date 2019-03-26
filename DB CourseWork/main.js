"use strict";

var json;

function trigger() {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
        json = xhttp.responseText;
        console.log(json);
    }
  };
  xhttp.open("GET", "./main.py", true);
  xhttp.send();
}

function pacientAuth() {
    var
        login = "",
        password = "";


    login = prompt("Введите логин");
    password = prompt("Введите пароль");

    trigger();

    // метод запроса к БД

}

function doctorAuth() {
        var
        login = "",
        password = "";

    login = prompt("Введите логин");
    password = prompt("Введите пароль");

    // метод запроса к БД
}