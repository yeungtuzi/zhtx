//
// cangjingge.c 雪山藏经室
// by secret
// /d/xizang/cangjingge.c

inherit ROOM;

// 修改藏书
string* books = ({
        __DIR__"obj/book1",
        __DIR__"obj/book2",
        __DIR__"obj/book3",
        __DIR__"obj/book4",
//        "/d/xueshan/obj/skin",
//        "/d/xueshan/obj/jing",
//        "/d/shaolin/obj/book-bamboo",
//        "/d/shaolin/obj/book-silk",
//        "/d/shaolin/obj/book-stone",
//        "/d/shaolin/obj/book-iron",
});

void create()
{
        set("short", "雪山藏经室");
        set("long", @LONG
这里是雪山寺的藏经室，靠墙是一排书架，摆满了各种拳谱、书籍。
大多是当年掌门人鸠摩智翻译的佛经和从少林寺取来的武学典籍。
LONG
        );

        set("exits", ([
                "east" : __DIR__"zoulang3",
		  "up" : __DIR__"upcjg",
        ]));

        set("objects", ([
                books[random(sizeof(books))] : 1,
                books[random(sizeof(books))] : 1,
                books[random(sizeof(books))] : 1,
        ]));

        setup();
        replace_program(ROOM);
}
