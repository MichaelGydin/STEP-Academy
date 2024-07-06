window.onload = function() {
    const defaultCity = "Rivne";
    const apiKey = "d4a52ccbf4504eb4916142034233110";
    const url = `http://api.weatherapi.com/v1/current.json?key=${apiKey}&q=${defaultCity}&lang=uk`;
    sendRequest(url);
};

function showWeather(weather) {
    const tempElement = document.getElementById("temp");
    const cityElement = document.getElementById("city");
    const countryElement = document.getElementById("country");
    const windSpeedElement = document.getElementById("windSpeed");
    const windDirElement = document.getElementById("windDir");
    const cloudElement = document.getElementById("cloud");
    const cloudIcon = document.getElementById("cloudIcon");

    cityElement.innerText = `Місто: ${weather.location.name}`;
    countryElement.innerText = `Країна: ${weather.location.country}`;
    tempElement.innerHTML = `Температура: ${weather.current.temp_c}&degC`;
    windSpeedElement.innerText = `Швидкість вітру: ${weather.current.wind_kph} км/год`;
    windDirElement.innerText = `Напрямок вітру: ${weather.current.wind_dir}`;
    cloudElement.innerText = `Хмарність: ${weather.current.cloud}%`;
    cloudIcon.setAttribute("src", `http:${weather.current.condition.icon}`);
    cloudIcon.setAttribute("alt", weather.current.condition.text);
}

function changeCity() {
    const city = document.getElementById("cityField").value;
    const apiKey = "d4a52ccbf4504eb4916142034233110";
    const requestUrl = `http://api.weatherapi.com/v1/current.json?key=${apiKey}&q=${city}&lang=uk`;
    sendRequest(requestUrl);
}

function sendRequest(url) {
    const request = new XMLHttpRequest();

    function responseHandler() {
        const json = request.responseText;
        const weather = JSON.parse(json);
        console.log(weather);
    
        showWeather(weather);
    }

    request.onload = responseHandler;

    request.open("GET", url);
    request.send();
}

function getDog() {
    const dogApiUrl = "https://dog.ceo/api/breeds/image/random";
    const request = new XMLHttpRequest();

    function responseDogApiHandler() {
        const json = request.responseText;
        const dog = JSON.parse(json);

        const img = document.getElementById("imgDog");
        img.setAttribute("src", dog.message)
    }

    request.onload = responseDogApiHandler;

    request.open("GET", dogApiUrl);
    request.send();
}
