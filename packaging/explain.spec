```spec
Name:           explain
Version:        1.0.0
Release:        1%{?dist}
Summary:        Fast command-line utility for terminal workflow automation and API querying

License:        LicenseRef-Proprietary
URL:            https://github.com/not-saturno/explain
Source0:        %{name}-%{version}.tar.gz

BuildRequires:  cmake
BuildRequires:  gcc-c++
BuildRequires:  make
BuildRequires:  cpr-devel
BuildRequires:  json-devel

%description
Fast command-line utility designed for terminal workflow automation
and API querying.

%prep
%autosetup

%build
%cmake
%cmake_build

%install
%cmake_install

%files
%{_bindir}/explain

%changelog
* Sat Oct 03 2026 Jean Remedios <not-saturno@users.noreply.github.com> - 1.0.0-1
- Initial package
```
