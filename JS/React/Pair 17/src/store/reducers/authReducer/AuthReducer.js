const initialState = {
    user: JSON.parse(localStorage.getItem('user')) || null,
    error: null,
};

const authReducer = (state = initialState, action) => {
    switch (action.type) {
        case 'SIGNUP_SUCCESS':
            return {
                ...state,
                user: action.payload,
            };
        case 'SIGNUP_ERROR':
            return {
                ...state,
                error: action.payload,
            };
        default:
            return state;
    }
};

export default authReducer;