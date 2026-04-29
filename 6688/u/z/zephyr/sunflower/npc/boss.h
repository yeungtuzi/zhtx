int accept_kill(object me)
{
        object ob;
        if(ob=present("jian nu",environment()))
        {
                ob->kill_ob(me);
                me->kill_ob(ob);
        }
        if(ob=present("dao nu",environment()))
        {
                ob->kill_ob(me);
                me->kill_ob(ob);
        }
        if(ob=present("qiang nu",environment()))
        {
                ob->kill_ob(me);
                me->kill_ob(ob);
        }
        if(ob=present("cha nu",environment()))
        {
                ob->kill_ob(me);
                me->kill_ob(ob);
        }
        if(ob=present("ji nu",environment()))
        {
                ob->kill_ob(me);
                me->kill_ob(ob);
        }
        if(ob=present("zhang nu",environment()))
        {
                ob->kill_ob(me);
                me->kill_ob(ob);
        }
        if(ob=present("fu nu",environment()))
        {
                ob->kill_ob(me);
                me->kill_ob(ob);
        }
        if(ob=present("quan nu",environment()))
        {
                ob->kill_ob(me);
                me->kill_ob(ob);
        }
        if(ob=present("bian nu",environment()))
        {
                ob->kill_ob(me);
                me->kill_ob(ob);
        }
        return 1;
}
