
inherit ROOM;

void create()
{
        set("short", "谷地");
        set("long", @LONG
只见四下流泉白石，奇松异草，将这四山环绕的谷地，点缀得有如神仙世
界一般。前面水声渐大，一条白练也似的瀑布垂于面前。
LONG
        );
        set("exits", ([ 
  	"north" : __DIR__"smalllake",
  	"west" : __DIR__"garden3",
]));
        set("outdoors", "mingjiao");

        setup();
        replace_program(ROOM);
}

