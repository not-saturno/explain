Name:           explain
Version:        1.0.0
Release:        1%{?dist}
Summary:        Terminal tool with API integration
License:        MIT
URL:            https://github.com/not-saturno/explain

BuildRequires:  cmake
BuildRequires:  gcc-c++

%description
Terminal utility for API explanations and querying.

%prep
# COPR clones the git repository automatically

%build
%cmake
%cmake_build

%install
%cmake_install

%files
%{_bindir}/explain