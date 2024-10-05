const initAuthState = {
    isAuth: false,
    user: null
};

const AuthReducer = (state = initAuthState, action) => {
    switch(action.type) {
        case "SIGN_IN":
            return { ...state, isAuth: true, user: action.payload };
        case "LOGOUT":
            return { ...state, isAuth: false, user: null };
        default:
            return state;
    }
};

export default AuthReducer;