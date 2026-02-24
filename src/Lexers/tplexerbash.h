#ifndef TPLEXERBASH_H
#define TPLEXERBASH_H

#include <Lexers/TpGeneralLexer>

TP_NAMESPACE

inline const char *lexerBashKeyword1 =
"accept access accton aclocal aconnect acpi acpi_available acpid addr2line addresses agetty alias alsactl amidi amixer "
"anacron aplay aplaymidi apm apmd apropos apt apt-get aptitude ar arch arecord arecordmidi arp as aspell at atd atq "
"atrm audiosend aumix autoconf autoheader automake autoreconf autoscan autoupdate awk badblocks banner basename bash "
"batch bc bg biff bind bison break builtin bzcmp bzdiff bzgrep bzip2 bzless bzmore cal cardctl cardmgr case cat cc "
"ccrypt cd cdda2wav cdparanoia cdrdao cdrecord cfdisk chage chattr chdir chfn chgrp chkconfig  chmod chown chpasswd "
"chroot chrt chsh chvt cksum clear cmp col colcrt colrm column comm command compress continue cp cpio cpp cron crond "
"crontab csplit ctags cupsd curl cut cvs date dc dd ddrescue deallocvt debugfs declare depmod devdump df diff diff3 "
"dig dir dircolors dirname dirs disable dlpsh dmesg dmidecode dnsdomainname dnssec-keygen dnssec-makekeyset "
"dnssec-signkey dnssec-signzone doexec domainname dosfsck dpkg dstat du dump dumpe2fs dumpkeys e2fsck e2image e2label "
"echo ed edquota egrep eject elvutune emacs enable env envsubst esd esd-config esdcat esdctl esddsp esdmon esdplay "
"esdrec esdsample etags ethtool eval ex exec exit expand expect export expr factor false fc fc-cache fc-list fdformat "
"fdisk fetchmail fg fgconsole fgrep file find finger fingerd flex fmt fold for formail format free fsck ftp ftpd "
"function Fun fuser g++ gawk gcc gdb getent getkeycodes getopts gpasswd gpg gpgsplit gpgv gpm gprof grep groff groffer "
"groupadd groupdel groupmod groups grpck grpconv gs gunzip gzexe gzip halt hash hdparm head help hexdump history host "
"hostid hostname hostnamectl htdigest htop hwclock iconv id if ifconfig ifdown iftop ifup imapd import inetd info init "
"insmod install iostat iotop ip ipcrm ipcs iptables iptables-restore iptables-save iwconfig isodump isoinfo isosize "
"isovfy ispell jobs join journalctly kbd_mode kbdrate kill killall killall5 klogd kudzu last lastb lastlog ld ldconfig "
"ldd less lesskey let lftp lftpget link ln loadkeys local locale locate lockfile logger login logname logout logrotate "
"look losetup lpadmin lpc lpinfo lpmove lpq lpr lprint lprintd lprintq lprm lpstat ls lsattr lsblk lshw lsmod lsof "
"lspci lsusb m4 mail mailq mailstats mailto make makedbm makemap man manpath mattrib mbadblocks mcat mcd mcopy md5sum "
"mdel mdeltree mdir mdu merge mesg metamail metasend mformat mimencode minfo mkdir mkdosfs mke2fs mkfifo mkfs "
"mkfs.ext3 mkisofs mklost+found mkmanifest mknod mkraid mkswap mktemp klabel mmd mmount mmove mmv modinfo modprobe "
"more most mount mountd mpartition mpstat mpg123 mpg321 mrd mren mshowfat mt mtools mtoolstest mtr mtype mv mzip named "
"namei nameif nc netstat newaliases newgrp newusers nfsd nfsstat nice nl nm nohup notify-send nslookup nsupdate "
"objcopy objdump od op open openvt passwd paste patch pathchk perl pgrep pidof ping pinky pkill pmap popd portmap "
"poweroff pppd pr praliases printcap printenv printf ps ptx pushd pv pwck pwconv pwd python quota quotacheck quotactl "
"quotaoff quotaon quatastats raidstart ram ramsize ranlib rar rarpd rcp rdate rdev rdist rdistd read readarray readcd "
"readelf readlink readonly reboot reject remsync rename renice repquota reset resize2fs restore return rev rexec "
"rexecd richtext rlogin rlogind rm rmail rmdir rmmod rndc rootflags route routed rpcgen rpcinfo rpm rsh rshd rsync "
"runlevel rup ruptime rusers rusersd rwall rwho rwhod scane-find-scanner sar scanadf scanimage scp screen script "
"scriptreplay sdiff sed select sendmail sensors seq service set setfdprm setkeycodes setleds setmetamode setquota "
"setsid setterm sftp sh sha1sum shift shopt showkey showmount shred shutdown size skill slabtop slattach sleep slocate "
"snice sort source split ss ssh ssh-add ssh-agent ssh-keygen ssh-keyscan sshd stat statd strace strfile strings strip "
"stty su sudo sum suspend swapoff swapon symlink sync sysctl sysklogd syslogd systemctl tac tail tailf talk talkd tar "
"taskset tcpd tcpdump tcpslice tee telint telnet telnetd test tftp tftpd time timeout times tload tmpwatch top touch "
"tput tr tracepath traceroute trap tree troff TRUE test tsort tty tune2fs tunelp type ul ulimit umask umount unalias "
"uname uncompress unexpand unicode_start unicode_stop uniq units unix2dos unrar unset unshar until uptime useradd "
"userdel usermod username users usleep uudecode uuencode uuidgen vdir vi vidmode vim vmstat vnstat volname w wait wall "
"warnquota watch wc wget whatis whereis which while who whoami whois write xargs xdg-open xinetd xc yacc yes ypbind "
"ypcat ypinit ypmatch yppasswd yppoll yppush ypserv ypset yptest ypwhich ypxfr zcat zcmp zdiff zdump zforce zgrep zic "
"zip zless zmore znew"
" "
"alias ar asa awk banner basename bash bc bdiff break bunzip2 bzip2 cal calendar case cat cc cd chmod cksum clear cmp "
"col comm compress continue cp cpio crypt csplit ctags cut date dc dd declare deroff dev df diff diff3 dircmp dirname "
"do done du echo ed egrep elif else env esac eval ex exec exit expand export expr false fc fgrep fi file find fmt fold "
"for function functions getconf getopt getopts grep gres hash head help history iconv id if in integer jobs join kill "
"local lc let line ln logname look ls m4 mail mailx make man mkdir more mt mv newgrp nl nm nohup ntps od pack paste "
"patch pathchk pax pcat perl pg pr print printf ps pwd read readonly red return rev rm rmdir sed select set sh shift "
"size sleep sort spell split start stop strings strip stty sum suspend sync tail tar tee test then time times touch tr "
"trap true tsort tty type typeset ulimit umask unalias uname uncompress unexpand uniq unpack unset until uudecode "
"uuencode vi vim vpax wait wc whence which while who wpaste wstart xargs zcat chgrp chown chroot dir dircolors factor "
"groups hostid install link md5sum mkfifo mknod nice pinky printenv ptx readlink seq sha1sum shred stat su tac unlink "
"users vdir whoami yes";

class TpLexerBash : public TpGeneralLexer
{
    Q_OBJECT

    DEF_PROP(bool, foldComments);
    DEF_PROP(bool, foldCompact);

public:
    enum
    {
        Default = 0,
        Error = 1,
        Comment = 2,
        Number = 3,
        Keyword = 4,
        DoubleQuotedString = 5,
        SingleQuotedString = 6,
        Operator = 7,
        Identifier = 8,
        Scalar = 9,
        ParameterExpansion = 10,
        Backticks = 11,
        HereDocumentDelimiter = 12,
        SingleQuotedHereDocument = 13,
    };

    enum
    {
        PropFoldComments,
        PropFoldCompact,
    };

public:
    TpLexerBash(QObject *parent = nullptr);
    virtual ~TpLexerBash();

public:
    const char *language() const override;
    const char *lexer() const override;
    int braceStyle() const override;
    const char *wordCharacters() const override;

    QColor defaultColor(int style) const override;
    bool defaultEolFill(int style) const override;
    QFont defaultFont(int style) const override;
    QColor defaultPaper(int style) const override;

    const char *keywords(int set) const override;
    QString description(int style) const override;

    void refreshProperties() override;

    void setLexerProperty(int prop, QVariant value) override;
    QVariant lexerProperty(int prop) const override;

protected:
    bool readProperties(QSettings &settings, const QString &prefix) override;
    bool writeProperties(QSettings &settings, const QString &prefix) const override;
};

TP_END_NAMESPACE

#endif // TPLEXERBASH_H
