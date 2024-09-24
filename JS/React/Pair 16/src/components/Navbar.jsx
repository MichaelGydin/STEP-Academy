import React from 'react';
import { useDispatch } from 'react-redux';
import { logout } from '../store/actions/authActions';

const Navbar = () => {
    const dispatch = useDispatch();

    const handleLogout = () => {
        dispatch(logout());
    };

    return (
        <nav>
            {/* Інші елементи навігації */}
            <button onClick={handleLogout}>Logout</button>
        </nav>
    );
};

export default Navbar;