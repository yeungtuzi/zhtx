#include <ansi.h>

inherit NPC;
inherit F_VENDOR;

string ask_me();

void create()
{
    set_name(HIC"茅山小道"NOR, ({ "husband" }) );
    set("gender", "男性" );
    set("age", 22);
    set("long",
            "哎！别看了！茅山小道正搂着小桂子打啵呢。\n");
    set("combat_exp", 5);
    set("attitude", "friendly");
    set("rank_info/respect", "同志");
     set("chat_msg", ({
//      "茅山小道笑咪咪地对小桂子说：“老婆，来，香一个！”。\n",
        "茅山小道“嘿嘿”地偷笑。\n",        
        }) );

set("inquiry", ([
    "已经被宰" : (: ask_me :),
        ]) );

       setup();
}

void init()
{   
    object ob;

    ::init();
    if( interactive(ob = this_player()) && !is_fighting() ) {
            remove_call_out("greeting");
            call_out("greeting", 1, ob);
    }

}

string ask_me()
{
   object me;
   string str;
   me = this_player();
   str = "茅山小道翻了翻白眼,";

   if(me->query("marks/点菜") != 1) {
           str+="你觉得浑身不舒服起来.\n";
           tell_object(me, str);
           str= "还想骗我？不买不让走，这是规矩.\n";
           return str;
   }
   str+="你豪气陡生,露出无所畏惧的表情.\n";
   tell_object(me, str);
   str= "去吧!\n";
   environment(this_object())->open_passage();
   return str;
}




