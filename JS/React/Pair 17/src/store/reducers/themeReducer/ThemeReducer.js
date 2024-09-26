const initialState = {
    isDark: JSON.parse(localStorage.getItem('isDark')) || false,
};

const themeReducer = (state = initialState, action) => {
    switch (action.type) {
        case 'TOGGLE_THEME':
            const newTheme = !state.isDark;
            localStorage.setItem('isDark', JSON.stringify(newTheme));
            return {
                ...state,
                isDark: newTheme,
            };
        default:
            return state;
    }
};

export default themeReducer;
