// keting3.c 客厅
// by Masterall
 
inherit ROOM;
void create()
{set("short", "客厅");
set("long", @LONG
    这是一间收拾的安静利落的客厅，桌边摆着一盆万年青，点着檀香，沁人心脾
，一个人正坐在椅子上品茶。看似非常惬意的房间却因为这个人的存在而变得杀气
腾腾。
LONG
        );
 
        set("exits", ([
                "west" : __DIR__"shibanlu2",
        ]));
set("objects",([
                 __DIR__"npc/yu" : 1,
         ]));
setup();
replace_program(ROOM);
} 
 

