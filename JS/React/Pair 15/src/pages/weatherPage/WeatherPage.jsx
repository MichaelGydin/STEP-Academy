import React, { useState, useEffect } from "react";
import axios from "axios";
import { Box, TextField, Button, Typography, CircularProgress } from "@mui/material";
import './WeatherPage.css';

function WeatherPage() {
    const [city, setCity] = useState("Rivne");
    const [weather, setWeather] = useState(null);
    const [loading, setLoading] = useState(false);
    const [error, setError] = useState(null);

    const apiKey = "9c8ba75b0a7544bf87d173654242904";
    const url = `https://api.weatherapi.com/v1/current.json?key=${apiKey}&q=${city}`;

    const Style = {
        margin: "20px 0px 0px"
    };

    useEffect(() => {
        fetchWeather();
    }, [city]);

    const fetchWeather = () => {
        setLoading(true);
        axios
            .get(url)
            .then((response) => {
                setWeather(response.data);
                setLoading(false);
                setError(null);
            })
            .catch((error) => {
                setError("Failed to fetch weather data");
                setLoading(false);
            });
    };

    const handleCityChange = (event) => {
        setCity(event.target.value);
    };

    return (
        <Box className="weather-container">
            <Typography className="weather-title" variant="h4">Weather</Typography>
            <TextField
                className="weather-input"
                label="Enter city"
                variant="outlined"
                value={city}
                onChange={handleCityChange}
            />
            <Button className="weather-button" variant="contained" onClick={fetchWeather} style={Style}>Get Weather</Button>
            {loading && <CircularProgress className="weather-progress" />}
            {error && <Typography className="weather-error">{error}</Typography>}
            {weather && (
                <Box className="weather-info">
                    <Typography variant="h6">{weather.location.name}, {weather.location.region}, {weather.location.country}</Typography>
                    <Typography variant="body1">Date and Time: {weather.location.localtime}</Typography>
                    <Typography variant="body1">Temperature: {weather.current.temp_c}°C</Typography>
                    <Typography variant="body1">Pressure: {weather.current.pressure_mb} mb</Typography>
                    <Typography variant="body1">Wind Speed: {weather.current.wind_kph} kph</Typography>
                    <Typography variant="body1">Wind Direction: {weather.current.wind_dir}</Typography>
                    <Typography variant="body1">Cloudiness: {weather.current.cloud}%</Typography>
                    <img src={`https:${weather.current.condition.icon}`} alt={weather.current.condition.text} />
                    <Typography variant="body1">{weather.current.condition.text}</Typography>
                </Box>
            )}
        </Box>
    );
}

export default WeatherPage;
