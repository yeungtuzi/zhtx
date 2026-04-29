// newbie area's guard
// 海娃
// 自动导航程序
// by dongsw

#include <ansi.h>

inherit NPC;
inherit __DIR__"guard.c";

#define NEWB_DIR "/d/newb/"

void create()
{
        object ob;
        set_name("海娃", ({ "hai wa","boy"}) );
        set("gender", "男性" );
        set("age", 12);
        set("title", HIG"新手村 "CYN"接引使"NOR);
        set("long","他是新手村中年龄最小的人，但是他在新手村里面的地位可是非同一般，他是新手村\n"
                   "的接引使和导游。专门给新人介绍新手村的信息。\n");
        set("combat_exp", 50000);

        carry_object("/obj/cloth")->wear();
        setup();

}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 5, ob);
        }
}

void greeting(object ob)
{
        tell_object(ob, CYN"\n海娃：“" + ob->name() + "，这里是新手村的祭坛，我是专门负责指导新人如何容入新手村这个大家庭的接引使。”\n"
                           "海娃：“需要我带你逛逛新手村的各个地方，并且告诉你如何开始游戏吗？”(y/n)\n");
        input_to("ask_guard",ob);       
}

int ask_guard(string arg, object me)
{
        if( arg == "n" || arg == "N")
        {
                tell_object(me, CYN"海娃：“好吧，想来你对新手村应该有了一定的了解，我就不多费唇舌了。”\n"
                                   "海娃：“" + me->name() + "跟我来，这边走，我带你去村长家，他会给你提供些帮助。”\n");
                write(WHT"\n海娃领着你走出了祭坛，你们走在无尽的旷野中......\n\n"NOR);
                me->move("/d/newb/kuangye");
                me->start_busy(20);
                call_out("move_to_area", 10, me, 0);
        }
        else
        {
                tell_object(me, CYN"海娃：“好吧，我带你去新手村逛逛，我们先走出这偏旷野，去新手村的新村广场看看。”\n"NOR);
                write(WHT"\n海娃领着你走出了祭坛，你们走在无尽的旷野中......\n\n"NOR);
                me->move("/d/newb/kuangye");
                me->start_busy(20);
                call_out("visit_area", 10, me, 0);
        }
        
        return 1;
}

int visit_area(object me, int i, object npc)
{
        mapping intro, nintro;
        string msg, path, here, next, npath;
        int k;
        
        if(i == sizeof(guard) - 1)
        {
                destruct(npc);
                me->start_busy(20);
                call_out("move_to_area", 10, me, 1);
                return 1;
        }
                        
        for(k=0;k<sizeof(guard);k++)
        {
                if(guard[k]["id"] == i  )  intro = guard[k];
                if(guard[k]["id"] == i+1) nintro = guard[k];
        }

        path = NEWB_DIR + intro["file"];
        npath = NEWB_DIR + nintro["file"];

        msg = intro["intro"];

        here = REPLACE_D->ansi_remove(load_object(path)->query("short"));
        next = REPLACE_D->ansi_remove(load_object(npath)->query("short"));

        if(npc) destruct(npc);
        npc = new("/d/newb/npc/boy2");
        me->interrupt_me(me, "death");
        
        write(REF WHT"\n海娃：“" + RANK_D->query_respect(me) + "，这边走，" + here + "到了！”\n\n"NOR);
        
        npc->move(path);
        me->move(path);
        
        write(CYN"\n海娃：“这里就是" + here + "了，" + msg + "你四下看看，马上我们去" + next + "看看。”\n\n"NOR);

        me->start_busy(30);
        i++;
        call_out("visit_area", 20, me, i, npc);
        return 1;
}

int move_to_area(object me, int FLAG)
{
        object npc = new(__DIR__"boy2.c");
        
        me->interrupt_me(me, "death");
        
        if( FLAG == 0 ) write(WHT"\n海娃带了走了好久，终于到达了新手村的村长家。\n\n"NOR);
        if( FLAG == 1 ) write(REF WHT"\n海娃：“" + RANK_D->query_respect(me) + "，这边走，村长家到了！”\n\n"NOR);
        
        npc->move("/d/newb/houyuan");
        me->move("/d/newb/houyuan");
        
        write("\n");
        write(CYN"海娃：“这位" + RANK_D->query_respect(me) + "，这里就是村长家了，你的纵横天下生涯从现在正式开始了。”\n"
                 "海娃：“我的任务已经完成，就此告辞！”\n\n"
              WHT"海娃消失在茫茫人海中了.....\n\n"NOR);
        
        me->set("startroom", "/d/newb/houyuan");
        destruct(npc);
        return 1;
}

