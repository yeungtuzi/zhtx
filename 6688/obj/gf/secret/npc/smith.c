// smith.c 铁匠

#include <ansi.h> 

inherit NPC;
inherit F_VENDOR;

void ask_me();

void create()
{
        set_name(YEL"王铁匠"NOR, ({ "tiejiang wang", "wang" }));
        set("title", "铁匠铺老板");
        set("shen_type", 1);
                
                set("count",1);
        set("gender", "男性");
        set("age", 80);
        set("long",
                MAG"王铁匠以打铁为生，他打造的兵器天下闻名。扬州的李铁匠不过是他一个不\n"
"成器的小弟子。有人甚至认为他比当年的欧冶子更牛。\n"NOR);
        set_skill("unarmed", 80);
        set_skill("dodge", 80);
        set_temp("apply/damage", 50);

          set("inquiry",([
                "灵空剑"    : (: ask_me :),
        ]));

        set("combat_exp", 50000);
        set("attitude", "friendly");
        set("vendor_goods", ([
                __DIR__"obj/yblade":10,
                __DIR__"obj/staff":15,
                __DIR__"obj/kaijia":15,
        ]));

        setup();
}

void init()
{
        add_action("do_vendor_list", "list");
}


void ask_me()
{
        object jian;
        if (!query("count")) return;
        if (!this_player()->query_temp("weaponor5")) return;
        command("say 灵空剑？你从哪儿听到的这个名字？");
        message_vision("$N向王铁匠如此这般解释一番...",environment());
        command("hmm");
        command("say 原来如此。我的确有一把上古流传下来的宝剑。此剑凶险无比，你....");
        message_vision("$N说道，此剑并非我要取用，而是要归还一位得到高人。",environment());
        command("nod");
        command("say 如此甚好。你且稍等。");
        message_vision("王铁匠回身到里屋去，片刻，他手持一柄红色的长剑出来，交给了你。",environment());
        jian=new("/obj/gf/secret/lingkongjian");
        jian->move(this_player());
        command("say 这就是那把凶剑了。切记，勿擅用。");
    add("count",-1);
        return;
}

