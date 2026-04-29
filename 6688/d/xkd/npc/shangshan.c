// shangshan.c 赏善使者
//by masterall
 
 
#include <ansi.h>
 
inherit NPC;

string ask_ling();
 
void consider();
 
void create()
{
        set_name("张三", ({ "zhang san", "zhang"}) );
 
        set("title", HIG "侠客岛"+HIY"赏善使者" NOR);
        set("gender", "男性");
        set("age", 40);
        set("long",
             "此人身材魁梧，圆脸大耳，穿一袭古铜色绸袍，笑嘻嘻地和蔼可亲。\n"
             "他直勾勾的盯着你，不知道打什么鬼注意，看得你脖子直发冷。\n"
        );
        set("attitude", "friendly");
        set("shen_type", 1);
        set("shen",3000000);
        set("str", 100);
        set("con", 100);
        set("int", 100);
        set("dex", 100);
        set("per", 30);
 
        set("force", 10000);
        set("max_force", 5000);
        set("force_factor", 250);
        set("max_kee", 5000);
        set("max_gin", 5000);
        set("max_sen", 5000);
 
        set("combat_exp", 50000000);
        set("score", 20000);

        set("inquiry", ([
                "侠客岛": "从此往东直蓬莱仙境，持有赏善罚恶令自然会有人接应你上岛。",
                "赏善罚恶令": (: ask_ling :),
        ]));
         set("chat_chance_combat", 100);
         set("chat_msg_combat", ({
                 (: consider :)
         }) );
 
         set_skill("force", 300);
         set_skill("dodge", 300);
         set_skill("mysterrier", 300);
         set_skill("xianglong-zhang",300);
         set_skill("strike",300);
         set_skill("parry", 300);
         set_skill("literate", 300);
         set_skill("jiuyang-shengong", 300);
         map_skill("force", "jiuyang-shengong");
         map_skill("parry", "xianglong-zhang");
         map_skill("strike", "xianglong-zhang");
         map_skill("dodge", "mysterrier");
         prepare_skill("strike", "xianglong-zhang");
         set_temp("jiuyang-shield", 1);

         setup();
         set_temp("apply/armor_vs_force",1000);
         set_temp("apply/armor",1000);
}

string ask_ling()
{
     object me = this_player();
     object ob,ling;

     if( !me->query("marks/银叶_credit"))
     return "你还没有破解银叶血案的秘密，不配索要赏善罚恶令！\n";

     if( !me->query("marks/app_dys"))
     return "你还没有破解金花婆婆的秘密，不配索要赏善罚恶令！\n";

//     if( !me->query("marks/42book"))
//     return "你还没有破解四十二章经的秘密，不配索要赏善罚恶令！\n";

     if( !me->query("marks/xixia/heliantieshu"))
     return "你还没有破解西夏赫连铁树的秘密，不配索要赏善罚恶令！\n";

     if( !me->query("pangban_winner"))
     return "你还没有杀死魔师庞斑，不配索要赏善罚恶令！\n";

//     if( !me->query("mpweapon_got"))
//     return "你还没有得到本派神兵，不配索要赏善罚恶令！\n";

     if (objectp(ling = present("shangshan fae ling",me) ) )
     return "你不是已经有赏善罚恶令了吗，怎么还要？太贪得无厌了吧！\n";  

     if (me->query("got_ling"))
     return "你不是已经要过一次赏善罚恶令了吗，有完没完了？！\n";  

     if( me->query("wlshw") < 25 )
     return "你在武林中的声望还不够高，还需在江湖中多做出几件翻天覆地的大事来！\n";

//     if( me->query("combat_exp") < 8000000 )
//     return "你的战斗经验太低了，有什么脸面去见贵派先人呢？\n";

        command("say 既然如此，那好吧。");
        command("say 凭此令可前往侠客岛寻找贵派前辈宗师。");
        command("say 他们那十几位老人家在岛上待了数十年，这回终于可以见到自己门下弟子了！");
                tell_object(me, HIW"赏善使者把赏善罚恶令交给了你！\n"NOR);      
                me->set("got_ling",1);
                ob=new("/d/xkd/obj/ling");
                ob->move(me);
                ob->set("owner", me);
}

