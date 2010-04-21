# ClassBを宣言（ClassAのサブクラスになります）

package ClassB ;

# パッケージAの使用を宣言
use ClassA;

# @ISAにスーパークラスの名前「A」を設定
# これによってクラスBはクラスAを継承する
@ISA = qw ( ClassA ); 

# ClassBのコンストラクタ
sub new {
    my $class = shift;

    # ClassAのコンストラクタを呼び出す
    my $self = new ClassA;
    return bless $self;
}
1
