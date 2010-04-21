#!/usr/bin/perl -w

use Socket;

$port = 4321;

#ソケットの生成
socket(CLIENT_WAITING, PF_INET, SOCK_STREAM, 0)||die "Can't create Socket";

#ソケットオプション設定
setsockopt(CLIENT_WAITING, SOL_SOCKET, SO_REUSEADDR, 1)||die "failure setsockopt()";

#ソケットへアドレス(名前)割り付け
bind(CLIENT_WAITING, pack_sockaddr_in($port, INADDR_ANY))||die "failure bind(). $!";

#ポートを監視
listen(CLIENT_WAITING, SOMAXCONN)||die "listen : $!";
print "ポート $port を見張ります \n";

#クライアント側のポートへの接続をポーリング
while (1) {
    $paddr = accept(CLIENT, CLIENT_WAITING);

    #ホスト名, IPアドレス, クライアントのポート番号を取得
    ($client_port, $client_iaddr) = unpack_sockaddr_in($paddr);
    $client_hostname = gethostbyaddr($client_iaddr, AF_INET);
    $client_ip = inet_ntoa($client_iaddr);

    print "Connect : $client_hostname ($client_ip), port : $client_port \n";

    #クライアントに対し、バッファリングしない
    select(CLIENT); $|=1; select(STDOUT);

    while (<CLIENT>) {
	print "Message : $_";

	#クライアントにメッセージを返す
	print CLIENT $_;
    }
    close(CLIENT);

    print "接続が切れました。引続きポート $port を見張ります \n";
}
