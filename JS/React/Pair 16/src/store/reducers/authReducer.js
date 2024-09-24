import { AUTH_SUCCESS, AUTH_LOGOUT } from '../actions/actionTypes';

const initialState = {
    isAuthenticated: false,
    user: null,
};

const authReducer = (state = initialState, action) => {
    switch (action.type) {
        case AUTH_SUCCESS:
            return {
                ...state,
                isAuthenticated: true,
                user: action.payload,
            };
        case AUTH_LOGOUT:
            return initialState;
        default:
            return state;
    }
};

export default authReducer;