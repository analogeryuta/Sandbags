# ClassA�������ClassB�Υ����ѡ����饹�ˤʤ�ޤ���
package ClassA;

# ���󥹥ȥ饯���κ���
sub new {
    my $class = shift;
    my $self = { x => 10 };
    bless $self,$class;
}
# �᥽�åɤκ���
sub print_x{
    my $self = shift;
    print $self->{x}, "\n";
}
1
