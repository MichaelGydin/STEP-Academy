import React from 'react';
import { AppBar, Toolbar, Container, Typography, Box, Button, IconButton, Menu, MenuItem } from '@mui/material';
import { Link } from 'react-router-dom';
import MenuIcon from '@mui/icons-material/Menu';
import DarkModeIcon from '@mui/icons-material/DarkMode';
import { useSelector, useDispatch } from 'react-redux';
import { Brightness4, Brightness7 } from '@mui/icons-material';
import { switchTheme } from '../store/reducers/themeReducer/actions';

const pages = [
  { id: 1, name: "Main", url: "/" },
  { id: 2, name: "News", url: "/news" },
  { id: 3, name: "Weather", url: "/weather" },
];

function Navbar() {
  const [anchorElNav, setAnchorElNav] = React.useState(null);

  const { isAuth, email } = useSelector((store) => store.authReducer);
  const dispatch = useDispatch();
  const { isDark } = useSelector(store => store.themeReducer);

  const handleOpenNavMenu = (event) => {
    setAnchorElNav(event.currentTarget);
  };

  const handleCloseNavMenu = () => {
    setAnchorElNav(null);
  };

  const logoutHandler = () => {
    dispatch(logout());
  };

  const toggleTheme = () => {
    dispatch(switchTheme());
  };

  return (
    <AppBar position="static">
      <Toolbar disableGutters>
        <Container maxWidth="xl">
          <Typography
            variant="h6"
            noWrap
            component="a"
            href="#app-bar-with-responsive-menu"
            sx={{
              mr: 2,
              display: { xs: "none", md: "flex" },
              fontFamily: "monospace",
              fontWeight: 700,
              letterSpacing: ".3rem",
              color: "inherit",
              textDecoration: "none",
            }}
          >
            LOGO
          </Typography>

          <Box
            sx={{
              flexGrow: 1,
              display: { xs: "flex", md: "none" },
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
                display: { xs: "block", md: "none" },
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

          <Box
            sx={{
              flexGrow: 1,
              display: { xs: "none", md: "flex" },
            }}
          >
            {pages.map((page) => (
              <Link to={page.url} key={page.id}>
                <Button
                  onClick={handleCloseNavMenu}
                  sx={{
                    my: 2,
                    color: "white",
                    display: "block",
                  }}
                >
                  {page.name}
                </Button>
              </Link>
            ))}
          </Box>

          <DarkModeIcon onClick={toggleTheme} sx={{ cursor: "pointer" }} />

          {isAuth === false ? (
            <Box sx={{ flexGrow: 0 }}>
              <Link to="/login">
                <Button sx={{ color: "white", mr: 2 }}>
                  Sign in
                </Button>
              </Link>
              <Link to="/register">
                <Button sx={{ color: "white", mr: 2 }}>
                  Sign up
                </Button>
              </Link>
            </Box>
          ) : (
            <Box sx={{ flexGrow: 0 }}>
              <Link to="/profile">
                <Button sx={{ color: "white", mr: 2 }}>
                  {email}
                </Button>
              </Link>
              <Button onClick={logoutHandler} sx={{ color: "white", mr: 2 }}>
                Logout
              </Button>
            </Box>
          )}
          <IconButton onClick={toggleTheme} color=" inherit">
            {isDark ? <Brightness7 /> : <Brightness4 />}
          </IconButton>
        </Container>
      </Toolbar>
    </AppBar>
  );
}

export default Navbar;