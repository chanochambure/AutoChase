#ifndef INCLUDED_AC_SCORE_H
#define INCLUDED_AC_SCORE_H

class ACScore
{
    private:
        LL_AL5::Image _V_score;
        float _V_limit_x_1;
        float _V_limit_x_2;
        float _V_limit_y_1;
        float _V_limit_y_2;
    public:
        ACScore()
        {
            _V_score.set_path(AC_SCORE_IMAGE_PATH);
            _V_score.set_centering_option(true,true);
        }
        void set_limits(float limit_x_1,float limit_x_2,float limit_y_1,float limit_y_2)
        {
            _V_limit_x_1=limit_x_1;
            _V_limit_x_2=limit_x_2;
            _V_limit_y_1=limit_y_1;
            _V_limit_y_2=limit_y_2;
        }
        void generate_new_pos()
        {
            _V_score.set_pos(LL::random(_V_limit_x_1,_V_limit_x_2),LL::random(_V_limit_y_1,_V_limit_y_2));
        }
        bool create_score()
        {
            return _V_score.load();
        }
        LL_AL5::Type_pos get_pos_x()
        {
            return _V_score.get_pos_x();
        }
        LL_AL5::Type_pos get_pos_y()
        {
            return _V_score.get_pos_y();
        }
        void set_pos(LL_AL5::Type_pos new_pos_x,LL_AL5::Type_pos new_pos_y)
        {
            _V_score.set_pos(new_pos_x,new_pos_y);
        }
        void draw()
        {
            _V_score.draw();
        }
        float get_size_x()
        {
            return _V_score.get_size_x();
        }
        float get_size_y()
        {
            return _V_score.get_size_y();
        }
};

#endif // INCLUDED_AC_SCORE_H
