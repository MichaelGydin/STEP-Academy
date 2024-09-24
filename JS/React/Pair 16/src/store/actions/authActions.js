import { AUTH_SUCCESS, AUTH_LOGOUT } from './actionTypes';

export const register = (userData) => {
    return dispatch => {
        localStorage.setItem('auth', JSON.stringify(userData));
    };
};

export const logout = () => {
    localStorage.removeItem('auth');
    return { type: AUTH_LOGOUT };
};
