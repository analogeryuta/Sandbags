package Class;

# コンストラクタ定義
sub new {
    my $class= shift;
    bless { x => shift }, $class;
}

# デストラクタ定義
sub DESTROY{
    my $self = shift;
    print "DESTROY > $self->{x}", "\n";
}
#-------------------------------------------------#
package main;

$a = new Class( '001' );
{
    my $b = new Class( '002' );
}
# $bがスコープ外となり、'002'のオブジェクトが破棄される

# '001'は上書きされ、そのオブジェクトが破棄される
$a = new Class( '003' );
