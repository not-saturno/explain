Name:           explain
Version:        1.0.0
Release:        1%{?dist}
Summary:        Terminal tool with API integration
License:        MIT
URL:            https://github.com/not-saturno/explain

Source0:        {{{ git_dir_pack }}}

BuildRequires:  cmake
BuildRequires:  gcc-c++

%description
Terminal utility for API explanations and querying.

%prep
%autosetup -T
tar -xzf %{SOURCE0}

%build
%cmake
%cmake_build

%install
%cmake_install

%files
%{_bindir}/explain

%changelog
* Sat Oct 03 2026 Jean Remédios not.saturno@proton.me - 1.0.0-1
- Initial package