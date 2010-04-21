# ClassAを宣言（ClassBのスーパークラスになります）
package ClassA;

# コンストラクタの作成
sub new {
    my $class = shift;
    my $self = { x => 10 };
    bless $self,$class;
}
# メソッドの作成
sub print_x{
    my $self = shift;
    print $self->{x}, "\n";
}
1
