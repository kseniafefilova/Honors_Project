{ pkgs }: {
	deps = [
   pkgs.shared-mime-info
   pkgs.libgccjit
		pkgs.clang_12
		pkgs.ccls
		pkgs.gdb
		pkgs.gnumake
    pkgs.wxGTK32
	];
}