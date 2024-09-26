export const signUp = (userData) => async (dispatch) => {
    try {
        const response = await fetch('/api/register', {
            method: 'POST',
            headers: {
                'Content-Type': 'application/json',
            },
            body: JSON.stringify(userData),
        });

        const data = await response.json();

        if (response.ok) {
            localStorage.setItem('user', JSON.stringify(data.user));

            dispatch({
                type: 'SIGNUP_SUCCESS',
                payload: data.user,
            });
        } else {
            dispatch({
                type: 'SIGNUP_ERROR',
                payload: data.message,
            });
        }
    } catch (error) {
        dispatch({
            type: 'SIGNUP_ERROR',
            payload: error.message,
        });
    }
};
