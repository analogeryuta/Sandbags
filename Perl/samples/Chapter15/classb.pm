# ClassB�������ClassA�Υ��֥��饹�ˤʤ�ޤ���

package ClassB ;

# �ѥå�����A�λ��Ѥ����
use ClassA;

# @ISA�˥����ѡ����饹��̾����A�פ�����
# ����ˤ�äƥ��饹B�ϥ��饹A��Ѿ�����
@ISA = qw ( ClassA ); 

# ClassB�Υ��󥹥ȥ饯��
sub new {
    my $class = shift;

    # ClassA�Υ��󥹥ȥ饯����ƤӽФ�
    my $self = new ClassA;
    return bless $self;
}
1
