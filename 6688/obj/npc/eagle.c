// /obj/npc/eagle.c

inherit NPC;

void create()
{
        set_name("大兀鹰", ({ "eagle", "condor", "ying" }) );
        set("race", "野兽");
        set("age", 3);
        set("long", "一只双翅张开长达丈二的黑色大兀鹰,看上去十分凶猛.\n");
        set("limbs", ({ "头部", "身体", "尾巴", "左翼", "右翼" }) );
        set("verbs", ({ "poke" , "claw" }) );
        set("str",50);
        set("cor",40);
        set("attitude","heroism");
        set("chat_chance", 15);
        set("chat_msg", ({
                (:random_move :)
        }) );
        set_skill("dodge", 200);
        set("combat_exp",40000);
        set("bellicosity",3000);
        set_temp("apply/attack",60);
        set_temp("apply/armor",40);
        setup();
}

int random_move()
{
        mapping exits;
        string *dirs;
        object room;
        string dir;

        if( !mapp(exits = environment()->query("exits")) ) return 0;
        dirs = keys(exits);
        dir = dirs[random(sizeof(dirs))];
        if( objectp(room = find_object(exits[dir])) 
                && (room->query("outdoors") == "eagle") )
                        command("go " + dir);
//eagle cannot fly indoors and don't want it fly out of eagle valley
}
