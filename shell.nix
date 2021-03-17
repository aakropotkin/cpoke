{ pkgs   ? import <nixpkgs> {},
  stdenv ? pkgs.stdenv,
  lib    ? pkgs.lib
}:

with lib;
stdenv.mkDerivation {
  name = "cpoke";  
  buildInputs = with pkgs; [
    gcc9
    curlFull.dev
    pcre.dev
    autoconf
    automake
  ];
}
