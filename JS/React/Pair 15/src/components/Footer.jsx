import React from "react";
import { Typography, Link } from "@mui/material";
import './Footer.css';

function Footer() {
    return (
        <footer className="footer">
            <Typography variant="body2" color="inherit">
                {"Copyright © "}
                <Link color="inherit" href="https://mui.com/">
                    Your Website
                </Link>{" "}
                {new Date().getFullYear()}
                {"."}
            </Typography>
        </footer>
    );
}

export default Footer;
