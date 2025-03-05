Name:    tictactoe
Version: 1.0
Release: alt1
Summary: Most simple RPM package
License: no
Group:   Development/Other
Source:  %name-%version.tar
BuildRequires: gcc-c++

%description
Hello world and roman sanich

%prep
%setup -n %name

%build
%make_build tictactoe

%install
mkdir -p %{buildroot}%_bindir
install -m 755 tictactoe %{buildroot}%_bindir

# Параметры для хранения файла max_score.txt
mkdir -p %{buildroot}%{_localstatedir}/lib/tictactoe

%post
# Создаем каталог при установке
if [ ! -d %{_localstatedir}/lib/tictactoe ]; then
    mkdir -p %{_localstatedir}/lib/tictactoe
fi

%postun
# Удаляем файл max_score.txt и каталог при удалении пакета
rmdir --ignore-fail-on-non-empty %{_localstatedir}/lib/tictactoe

%files
%_bindir/%name
%dir %{_localstatedir}/lib/tictactoe

%changelog
* Mon Apr 01 2024 Your Name <your_email@altlinux.org> 1.0-alt1
- Initial build
