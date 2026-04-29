// /d/xizang/class/snow_mnt/npc/secret.c
// by mscat

#include <ansi.h>
inherit NPC;

string ask_me();

void create()
{
        set_name("秘密", ({ "secret", "mimi", "mi" }));
        set("gender", "男性");
        set("age", 35);
        set("long", 
        "他本是中原巧匠,据说还是雪山寺的建造者,不知为什么给关在这里.\n");
        set("attitude", "peaceful");
        set("int", 30);
        set("str", 24);
        set("combat_exp", 500);
        set("shen", 100);
        set("inquiry", ([
                "秘密" : (: ask_me :),
                "name" : (: ask_me :),
                "here" : (: ask_me :),
                "逃走" : (: ask_me :)
        ]));

        set_skill("unarmed", 10);
        set("chat_chance", 5);
        set("chat_msg", ({
                "谁能帮我逃出去啊.....\n",
                "真倒霉.....\n",
                "竟然被锁在这里.....\n",
        }));
        setup();
        carry_object(OBJ_DIR"cloth")->wear();
}

void init()
{
        add_action("do_free", "free");
}

int do_free(string arg)
{
        if(!arg || (arg!="secret" && arg !="mimi" && arg !="mi"))
                return 0;
        message_vision(HIC"$N解开捆住秘密的铁链,把他放走了\n"NOR, 
                this_player());
        destruct(this_object());
}

string ask_me()
{
        object me;
        me=this_player();
        if (me->query("family/family_name")=="雪山寺") {
                command("shake");
                command("say 你们这群臭喇嘛,打死我也不会把秘密告诉你们的");
                return "哼......\n";
        }
        if (me->query("marks/secret")) {
                command("whisper "
                        +(string)me->query("id")+" 我知道的都已经和你说了");
                return "唉!\n";
        }
        me->set("marks/secret",1);
        command("whisper "
                +(string)me->query("id")+
                " 打开内殿密道的方法是....敲三下墙壁西北角");
        command("whisper "
                +(string)me->query("id")+
                " 记得回来帮我逃走.\n");
        return "唉!\n";
}

