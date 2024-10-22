import React from "react";
import { Navbar, Nav, Container } from 'react-bootstrap';
import { Link } from "react-router-dom";

function AppNavbar() {
    return (
        <Navbar bg="dark" variant="dark" className="mb-4 shadow-md">
            <Container>
                <Navbar.Brand as={Link} to="/" className="font-bold text-lg">
                    To-Do App
                </Navbar.Brand>
                <Nav className="ml-auto space-x-4">
                    <Nav.Link as={Link} to="/daily" className="text-white">
                        Daily
                    </Nav.Link>
                    <Nav.Link as={Link} to="/weekly" className="text-white">
                        Weekly
                    </Nav.Link>
                    <Nav.Link as={Link} to="/monthly" className="text-white">
                        Monthly
                    </Nav.Link>
                </Nav>
            </Container>
        </Navbar>
    );
}

export default AppNavbar;
