function toggleMenu() {
  var menuItems = document.getElementsByClassName("menu-items")[0];
  if (menuItems.style.display === "none" || menuItems.style.display === "") {
    menuItems.style.display = "block";
  } else {
    menuItems.style.display = "none";
  }
}