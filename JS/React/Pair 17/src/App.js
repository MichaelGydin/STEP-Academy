import "./App.css";
import MainPage from "./pages/mainPage/MainPage";
import NewsPage from "./pages/news/News";
import SignInPage from "./pages/auth/SignInPage";
import { Route, Routes } from "react-router-dom";
import DefaultLayout from "./components/layouts/DefaultLayout";
import NotFoundPage from "./pages/NotFoundPage";
import SignUpPage from "./pages/auth/SignUpPage";
import WeatherPage from "./pages/weatherPage/WeatherPage";
import { useAction } from "./hooks/useAction";
import { ThemeProvider } from "@mui/material";
import { darkTheme, lightTheme } from "./theming/themes";
import React, { useEffect } from "react";
import { useDispatch, useSelector } from "react-redux";


function App() {
    const { loginByLocalStorage } = useAction();
    const { isDark } = useSelector(store => store.themeReducer);
    const dispatch = useDispatch();

    loginByLocalStorage();

    let currentTheme = lightTheme;
    if (isDark) {
        currentTheme = darkTheme;
    }

    useEffect(() => {
        const storedTheme = JSON.parse(localStorage.getItem('isDark'));
        if (storedTheme !== null) {
            dispatch({ type: 'TOGGLE_THEME', payload: storedTheme });
        }
    }, [dispatch]);

    return (
        <div>
            <ThemeProvider theme={currentTheme}>
                <Routes>
                    <Route path="/" element={<DefaultLayout />}>
                        <Route index element={<MainPage />} />
                        <Route path="/news" element={<NewsPage />} />
                        <Route path="/login" element={<SignInPage />} />
                        <Route path="/register" element={<SignUpPage />} />
                        <Route path="/weather" element={<WeatherPage />} />
                        <Route path="*" element={<NotFoundPage />} />
                    </Route>
                </Routes>
            </ThemeProvider>
        </div>
    );
}

export default App;
