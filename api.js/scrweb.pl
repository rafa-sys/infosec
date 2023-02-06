# Realiza a varredura do texto buscando por vulnerabilidades conhecidas
my @vulnerabilities = ("SQL injection", "Cross-Site Scripting (XSS)", "File Inclusion");
my $vuln_found = 0;

foreach my $vuln (@vulnerabilities) {
    if ($text =~ /$vuln/i) {
        print "Vulnerabilidade encontrada: $vuln\n";
        $vuln_found = 1;
    }
}

if (!$vuln_found) {
    print "Nenhuma vulnerabilidade conhecida encontrada.\n";
}
