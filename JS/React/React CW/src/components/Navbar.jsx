import React from "react";
import AppBar from "@mui/material/AppBar";
import Box from "@mui/material/Box";
import Toolbar from "@mui/material/Toolbar";
import IconButton from "@mui/material/IconButton";
import Typography from "@mui/material/Typography";
import Menu from "@mui/material/Menu";
import MenuIcon from "@mui/icons-material/Menu";
import Container from "@mui/material/Container";
import Button from "@mui/material/Button";
import MenuItem from "@mui/material/MenuItem";
import AdbIcon from "@mui/icons-material/Adb";
import { Link } from "react-router-dom";
import { useSelector } from "react-redux";
import { useAction } from "../hooks/useAction";
import DarkModeIcon from '@mui/icons-material/DarkMode';
import LightModeIcon from '@mui/icons-material/LightMode'; // Import light mode icon

const pages = [
  { id: 1, name: "Main", url: "/" },
  { id: 2, name: "News", url: "/news" },
  { id: 3, name: "Weather", url: "/weather" },
];

function Navbar() {
  const [anchorElNav, setAnchorElNav] = React.useState(null);

  const { isAuth, user, theme } = useSelector((store) => store.authReducer);
  const { logout, switchTheme } = useAction();

  const handleOpenNavMenu = (event) => {
    setAnchorElNav(event.currentTarget);
  };

  const handleCloseNavMenu = () => {
    setAnchorElNav(null);
  };

  const logoutHandler = () => {
    logout();
  };

  const switchThemeHandler = () => {
    switchTheme(); // This should toggle the theme in your Redux store
  };

  return (
    <AppBar position="static" sx={{ backgroundColor: "#00d8ff" }}>
      <Container maxWidth="xl">
        <Toolbar disableGutters>
          <AdbIcon
            sx={{ display: { xs: "none", color: "#222222", md: "flex" }, mr: 1 }}
          />
          <Typography
            variant="h6"
            noWrap
            component="a"
            href="#app-bar-with-responsive-menu"
            sx={{
              mr: 2,
              display: { xs: "none", color: "#222222", md: "flex" },
              fontFamily: "monospace",
              fontWeight: 700,
              letterSpacing: ".3rem",
              color: "inherit",
              textDecoration: "none",
            }}
          >
            React
          </Typography>

          <Box
            sx={{
              flexGrow: 1,
              display: { xs: "flex", color: "#222222", md: "none" },
            }}
          >
            <IconButton
              size="large"
              aria-label="account of current user"
              aria-controls="menu-appbar"
              aria-haspopup="true"
              onClick={handleOpenNavMenu}
              color="inherit"
            >
              <MenuIcon />
            </IconButton>
            <Menu
              id="menu-appbar"
              anchorEl={anchorElNav}
              anchorOrigin={{
                vertical: "bottom",
                horizontal: "left",
              }}
              keepMounted
              transformOrigin={{
                vertical: "top",
                horizontal: "left",
              }}
              open={Boolean(anchorElNav)}
              onClose={handleCloseNavMenu}
              sx={{
                display: { xs: "block", color: "#222222", md: "none" },
              }}
            >
              {pages.map((page) => (
                <Link to={page.url} key={page.id}>
                  <MenuItem onClick={handleCloseNavMenu}>
                    <Typography textAlign="center">
                      {page.name}
                    </Typography>
                  </MenuItem>
                </Link>
              ))}
            </Menu>
          </Box>
          <AdbIcon
            sx={{ display: { xs: "flex", color: "#222222", md: "none" }, mr: 1 }}
          />
          <Typography
            variant="h5"
            noWrap
            component="a"
            href="#app-bar-with-responsive-menu"
            sx={{
              mr: 2,
              display: { xs: "flex", md: "none" },
              flexGrow: 1,
              fontFamily: "monospace",
              fontWeight: 700,
              letterSpacing: ".3rem",
              color: "blue",
              textDecoration: "none",
            }}
          >
            React
          </Typography>
          <Box
            sx={{
              flexGrow: 1,
              display: { xs: "none", color: "#222222", md: "flex" },
            }}
          >
            {pages.map((page) => (
              <Link to={page.url} key={page.id}>
                <Button
                  onClick={handleCloseNavMenu}
                  sx={{
                    my: 2,
                    color: "#222222",
                    display: "block",
                  }}
                >
                  {page.name}
                </Button>
              </Link>
            ))}
          </Box>
          <IconButton onClick={switchThemeHandler}>
            {theme === 'dark' ? <LightModeIcon /> : <DarkModeIcon />} {/* Toggle icon based on theme */}
          </IconButton>
          {isAuth ? (
            <Box sx={{ display: "flex", alignItems: "center" }}>
              <Link to="/profile">
                {user && user.image ? (
                  <img
                    src={user.image}
                    alt="User Avatar"
                    style={{
                      width: "40px",
                      height: "40px",
                      borderRadius: "50%",
                      marginRight: "10px",
                    }}
                  />
                ) : (
                  <Typography variant="h5">{user.email}</Typography>
                )}
              </Link>
              <Link to="/login">
                <Button
                  onClick={logoutHandler}
                  sx={{ color: "#222222", textDecoration: "none" }}
                >
                  Logout
                </Button>
              </Link>
            </Box>
          ) : (
            <Box sx={{ display: "flex", alignItems: "center" }}>
              <Link to="/login">
                <Button
                  sx={{ color: "#222222", textDecoration: "none" }}
                >
                  Login
                </Button>
              </Link>
              <Link to="/register">
                <Button
                  sx={{ color: "#222222", textDecoration: "none" }}
                >
                  Sign up
                </Button>
              </Link>
            </Box>
          )}
        </Toolbar>
      </Container>
    </AppBar>
  );
}

export default Navbar;
