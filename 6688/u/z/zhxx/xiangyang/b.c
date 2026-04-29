#include <ansi.h>

inherit "/std/char/doomnpc";


void create()
{
        set_name("挑夫", ({ "tiao fu", "porter" }) );
        set("gender", "男性" );
        set("age", 28);
        set("long",
                "这是个老实巴交的穷挑夫，长得膀阔腰圆，一身肌肉。\n");
//      set("shen_type", 1);
        set("combat_exp", 2000000);
        set("str", 25);
        set("dex", 22);
        set("con", 20);
        set("int", 15);
        set("shen",-9999999999);
        set("attitude", "heroism");

        setup();
         carry_object("/u/z/zhxx/wubook2.c");
carry_object("/u/z/zhxx/sword.c"); 
        carry_object("/u/z/zhxx/gift/a.c");
        carry_rnd_equip(7,7); 
}
